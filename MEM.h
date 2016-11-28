#ifndef MEM_H_INCLUDED
#define MEM_H_INCLUDED

#include<stdio.h>
#include <stdlib.h>

#define MEM_malloc(size) \
        (MEM_malloc_func(size, __FILE__ , __LINE__ ))
#define MEM_realloc(addr,size) \
        (MEM_realloc_func( addr , size , __FILE__ , __LINE__ ))
#define MEM_free(addr) \
        (MEM_free_func( addr , __FILE__ , __LINE__ ))
#define MEM_free_all() \
        (MEM_free_all_func( __FILE__ , __LINE__ ))

typedef struct MEM_block_tag MEM_block;

void*   MEM_malloc_func(size_t size, char *file_name, int line);
void*   MEM_realloc_func(void* addr, size_t size, char *file_name, int line);
void    MEM_free_func(void* addr, char *file_name, int line);
void    MEM_free_all_func(char *file_name, int line);
void    MEM_dump_block(MEM_block *block);
void    MEM_check_mem_block(); /* debug output all mem we alloced */

#endif // MEM_H_INCLUDED
