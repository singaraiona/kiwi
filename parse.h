#ifndef STRING_H
#define STRING_H

/**
*     File Name           :     string.h
*     Created By          :     
*     Creation Date       :     16-02-2015 12:51
*     Description         :      
***/

#include "type.h"

#define MAX_LINE_SZ 4096


S readline();
V parse(S);
V kprint(K);
V kerror();

#endif  /*STRING_H*/
