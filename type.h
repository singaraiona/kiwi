#ifndef TYPE_H
#define TYPE_H

/**
*     File Name           :     type.h
*     Created By          :     
*     Creation Date       :     16-02-2015 13:06
*     Description         :      
***/

typedef int I;
typedef char C,*S;
typedef void V;

#define R return
#define B break
#define O printf
#define SZ sizeof

#define OC(x) O("%c\n",x)
#define OS(x) O("%s\n",x)
#define OI(x) O("%d\n",x)
#define OU(x) O("%u\n",x)
#define OX(x) O("0x%X\n",x)

typedef struct Ktype {C value[128];} *K;
K ktree;

#endif  /*TYPE_H*/
