#ifndef TOKEN_H
#define TOKEN_H 
typedef struct TOKEN_STRUCT
{
    char*value;
    enum 
    {
        endOfFile
    } type;
} token_js;

token_js* init_token(char* value, int type);

#endif