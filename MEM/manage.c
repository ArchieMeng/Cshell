//
// Created by archie on 16-11-5.
//

#include "manage.h"

void insert(MEM_block *block)
{
    if(block == NULL)
        return;

    if(head == NULL)
    {
        head = block;
        head->pre = NULL;
        head->next = NULL;
    }
    else
    {
        MEM_block *p = head;
        head = block;
        block->next = p;
        p->pre = block;
        block->pre = NULL;
    }
}

void delete(MEM_block *block)
{
    if(block == NULL)
        return;

    MEM_block *pre = block->pre;
    MEM_block *next = block->next;
    if(pre)
    {
        pre->next = next;
    }
    if(next)
    {
        next->pre = pre;
    }
    if(head == block)
    {
        head = next;
    }

    free(block);
}

void update(MEM_block *old, MEM_block *new)
{
    if(old == NULL)
        return;

    if(old->pre)
    {
        MEM_block *pre = old->pre;
        pre->next = new;
    }
    if(old->next)
    {
        old->next->pre = new;
    }
    free(old);
}

MEM_block* find(void *mem_addr)
{
    MEM_block *p;
    if(mem_addr == NULL)
        return NULL;

    for (
            p = head;p != NULL;p = p->next)
    {
        if(p->mem == mem_addr)
            return p;
    }
    return NULL; /*failed to find this addr*/
}
