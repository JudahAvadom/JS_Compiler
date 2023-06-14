#include "include/js.h"
#include "include/lexer.h"
#include "include/io.h"
#include <stdio.h>

void compile(char* src){
    lexer_js* lexer = init_lexer(src);
}

void compile_file(const char* filename){
    char* src = read_file(filename);
    compile(src);
}