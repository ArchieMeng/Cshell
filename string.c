//
// Created by archie on 16-11-15.
//

#include<stdlib.h>
#include "errors.h"
#include "string.h"


//Todo consider how to manage string in memory (GC)

void    csm_open_string_literal()
{
    if (string)
    {
        csm_internal_error("open string literal twice",__FILE__,__LINE__);
    }
    block_size = 16;
    string = malloc(block_size);
    string_length = 0;
}

void    csm_add_string_literal(char ch)
{
    string[string_length] = ch;
    string_length++;
    if (string_length >= block_size)
    {
        block_size *= 2;
        string = realloc(string, block_size);
    }
}

char* csm_close_string_literal()
{
    return string;
}



