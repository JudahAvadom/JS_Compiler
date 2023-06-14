#include "include/js.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("Please, specify a input file \n");
        return 1;
    }
    compile_file(argv[1]);
    return 0;
}
