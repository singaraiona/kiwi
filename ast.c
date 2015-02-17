/**
*     File Name           :     ast.c
*     Created By          :     
*     Creation Date       :     16-02-2015 14:06
*     Description         :      
***/

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ast.h"

A* ast_init() {R (A*)mmap(NULL, ASTDEPTH, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANON, -1, 0);}
V ast_free(A* ast) {munmap(ast,ASTDEPTH);}
