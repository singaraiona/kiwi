#ifndef AST_H
#define AST_H

/**
*     File Name           :     ast.h
*     Created By          :     
*     Creation Date       :     16-02-2015 13:59
*     Description         :      
***/

#include "type.h"

typedef struct AstNode {I t; C val; struct Ast *l; struct Ast *r;} A;
#define ASTDEPTH SZ(A)

A* ast_init();
V ast_free(A*);

#endif  /*AST_H*/
