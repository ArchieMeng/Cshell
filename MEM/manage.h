//
// Created by archie on 16-11-5.
//

#ifndef CSHELL_MANAGE_H
#define CSHELL_MANAGE_H

#include "mem.h"

extern MEM_block *head;

MEM_block* find(void* mem_addr);
void insert(MEM_block *block);
void update(MEM_block *old,MEM_block *new);
void delete(MEM_block *block);

#endif //CSHELL_MANAGE_H
