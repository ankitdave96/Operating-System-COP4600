#ifndef _FILESECURITYTAG_H_
#define _FILESECURITYTAG_H_

int set_security_tag(const char *filename, int new_tag);
int get_security_tag(const char *filename);

#endif

