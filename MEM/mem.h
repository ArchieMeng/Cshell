//
// Created by archie on 16-10-16.
//

#ifndef CSHELL_MEM_H
#define CSHELL_MEM_H

#include <stdlib.h>
#include "../MEM.h"

typedef struct MEM_block_tag{
    size_t size;
    char *file_name;
    int line;
    void *mem;
    MEM_block *pre;
    MEM_block *next;
}MEM_block;

#endif //CSHELL_MEM_H
