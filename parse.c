/**
*     File Name           :     string.c
*     Created By          :     Anton Kundenko 
*     Creation Date       :     16-02-2015 13:14
*     Description         :     tokenizer 
***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type.h"
#include "ast.h"
#include "parse.h"

typedef struct Term {I offset; I len;} T;

S sterm = {":+-*%!&|<>=~,^#_$?@.'/\\[]{}()\0"};
S cterm[] = {"':\0","\\:\0","/:\0",NULL};

S readline(S line) {R fgets(line, MAX_LINE_SZ, stdin);}
V kprint(K k) {O(k->value);}
V kerror() {OS("parse:");} 
I ctermcmp(S s) {
    if(s[1]=='\n') R 0;
    S* a=cterm;
    for(;*a!=NULL;++a) {
       if(strncmp(s,*a,2)==0) {R 1;}
    }
    R 0;
}
I stermcmp(S s) {
    S v=sterm; 
    for(;*v!=0;++v) if(*v==*s) R 1;     
    R 0;
}
I termcmp(S s) {
    if(ctermcmp(s)) R 2;
    if(stermcmp(s)) R 1;
    R 0;
}
T nexterm(S line) {
    I l=0; 
    I termlen=0;
    T t;
    for(;!(termlen=termcmp(line));++l,++line) if(*line=='\n') break; 
    t.offset=l;
    t.len=termlen;
    R t;
}
I tokenize(I* tokens, S line) {
    I toks=0; 
    for(;;) {
        T t=nexterm(line); 
        if(t.offset) tokens[toks++]=t.offset; 
        line+=t.offset+t.len;
        if(!t.len) R toks;
        tokens[toks++]=t.len;
    } 
    R toks;
} 
V parse(S line) {
    I tokens[MAX_LINE_SZ];
    I toks=tokenize(tokens, line);
    OS("tokens:");
    for (I i=0; i<toks; ++i) {
        O("%.*s\n", tokens[i], line);
        line+=tokens[i];
    }
}
