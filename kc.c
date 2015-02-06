/**
*     File Name           :     j.c
*     Created By          :     
*     Creation Date       :     05-02-2015 12:29
*     Description         :      
***/

#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef unsigned I;typedef char C,*S;
#define R return
#define B break
#define O printf
#define V void

#define OC(x) O("%c\n",x)
#define OS(x) O("%s\n",x)
#define OI(x) O("%d\n",x)
#define OU(x) O("%u\n",x)
#define OX(x) O("0x%X\n",x)

#define RL(x) {I _c=0;while(_c=fgetc(stdin)){x(_c);}}
#define SZ(x) sizeof(x)
#define LN(x) strlen(x)

I assign=0;
I plus=1;
I minus=2;

typedef struct a0{I t; C v;struct a0 *r;} A;
#define SA SZ(A)
A *fnode = NULL;
A *lnode = NULL;

A *astinit() {R (A *)mmap(NULL, SA*10, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANON, -1, 0);}
I kinit() {fnode=astinit();if(!fnode)R 1;fnode->r=NULL; R 0;}
I newnode(C a,I b) {if(lnode){A *n=lnode+1;lnode->r=n;lnode=n;}else{lnode=fnode;} lnode->v=a;lnode->t=b; R 0;}
V kprint(A *n) {OC(n->v);}
V kproc() {A *n=fnode;for(;;){kprint(n);if(!n->r)B;n++;} }
V tok(c) {if(isdigit(c)){newnode(c,plus);}
          else if (c==0x0A) {kproc();} }
I main() {if(kinit())R 1;RL(tok);munmap(fnode,SA*10);R 0;}


