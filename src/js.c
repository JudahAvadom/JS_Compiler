#include "include/js.h"
#include "include/lexer.h"
#include "include/io.h"
#include "include/token.h"
#include <stdio.h>

void compile(char* src){
    lexer_js* lexer = init_lexer(src);
    token_js* tok = 0;
    while ((tok = lexer_next_token(lexer))->type != endOfFile)
    {
        printf("TOK(%S) (%d)\n", tok->value, tok->type);
    }
}

void compile_file(const char* filename){
    char* src = read_file(filename);
    compile(src);
}