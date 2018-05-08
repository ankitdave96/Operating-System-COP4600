#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/fs.h>
#include <string.h>
#include <fcntl.h>
#include "filesecuritytag.h"


#define SYS_get_sec 332
#define SYS_put_sec 333


int set_security_tag(const char *filename, int new_tag)
{
  int fd=0;
  int res=-1;

  if( access( filename, R_OK|W_OK ) != -1 ) {
    // file exists
    fd=open(filename,O_RDWR);
    char input[100];
    sprintf(input,"%d",new_tag);
//    itoa(new_tag, input, 10);
    res=syscall(SYS_put_sec, fd, input);

    return res;





} else {
    return -1;
    // file doesn't exist
}




}
int get_security_tag(const char *filename){

  int fd=0;
  int res=-1;

  if( access( filename, R_OK|W_OK ) != -1 ) {
    // file exists
//  if(access (filename, R_OK|W_OK ) == -1)
//      return -1;

    fd=open(filename,O_RDWR);

//    printf("Open done");
    char result[100];
    strcpy(result, "user.securitytag");
    res=syscall(SYS_get_sec, fd, result);
    if(res==-1)
{
//printf("the sys is the issue");
res=syscall(SYS_put_sec, fd, "0");
return res;
}

    res = atoi(result);
    return res;

} else {
    return -1;
    // file doesn't exist
}



}

