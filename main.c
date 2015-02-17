/**
*     File Name           :     main.c
*     Created By          :     
*     Creation Date       :     16-02-2015 13:07
*     Description         :      
***/
#include <stdio.h>
#include "ast.h"
#include "type.h"
#include "parse.h"

I main() {
    S ln = NULL;
    C line[MAX_LINE_SZ + 1];
    A* ast = ast_init();
    do {
        ln = readline(line);
        parse(line);        
    } while(ln);
    ast_free(ast);
    R 0;
}
