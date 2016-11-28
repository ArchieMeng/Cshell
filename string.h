//
// Created by archie on 16-11-15.
//

#include "CSM_dev.h"

#ifndef CSHELL_STRING_H
#define CSHELL_STRING_H

char *string;
size_t string_length;
size_t block_size;
void csm_open_string_literal();
void csm_add_string_literal(char);
char* csm_close_string_literal();
char* csm_string_add(CSM_String *str1,CSM_String *str2);

#endif //CSHELL_STRING_H
