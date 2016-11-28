//
// Created by archie on 16-11-5.
//

#include <memory.h>
#include "mem.h"
#include "manage.h"

MEM_block *head = NULL;

void* MEM_malloc_func(size_t size, char *file_name, int line)
{
    void *ptr;
    MEM_block* new_block;
    ptr = malloc(size);
    new_block = malloc(sizeof(MEM_block));
    new_block->mem = ptr;
    new_block->size = size;
    new_block->file_name = file_name;
    new_block->line = line;

    insert(new_block);

    return ptr;
}

void* MEM_realloc_func(void* addr, size_t size, char *file_name, int line)
{
    void *new_addr;
    MEM_block *block;
    new_addr = realloc(addr, size);
    block = find(addr);
    block->mem = new_addr;
    block->size = size;
    block->file_name = file_name;
    block->line = line;
    return new_addr;
}

void MEM_free_func(void *addr, char *file_name, int line)
{
    free(addr);
    delete(find(addr));
}

void MEM_check_mem_block()
{
    const MEM_block *p;
    printf("check mem block list!\n");
    for (p = head;p != NULL;p = p->next)
    {
        printf("addr=%p,size=%zu,alloc at line %d in file %s \n",p->mem,p->size,p->line,p->file_name);
    }
    putchar('\n');
}

void MEM_free_all_func(char *file_name, int line)
{
    MEM_block *p, *next_p;
    for(p = head;p != NULL;p = next_p)
    {
        next_p = p->next;
        MEM_free_func(p->mem, file_name, line);
    }
}

