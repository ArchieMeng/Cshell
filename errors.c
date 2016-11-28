//
// Created by archie on 16-11-15.
//

#include "errors.h"

void csm_internal_error(char *error_msg, char *file_name, int line)
{
    fprintf(stderr,"internal error at line %d in file %s:\t%s\n", line, file_name, error_msg);
    exit(1);
}