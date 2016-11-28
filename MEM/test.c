//
// Created by archie on 16-11-5.
//

#include "../MEM.h"

int main(void)
{
    int *pInt;
    double *pDouble;

    pInt = MEM_malloc(sizeof(int));
    printf("addr:%p,size:%ld\n",pInt,sizeof(int));
    MEM_check_mem_block();

    pDouble = MEM_malloc(sizeof(double));
    *pDouble = 1.23;
    printf("addr:%p,size:%ld,value:%f\n",pDouble,10*sizeof(double),*pDouble);
    MEM_check_mem_block();

    pDouble = MEM_realloc(pDouble, 10*sizeof(double));
    printf("addr:%p,size:%ld,value:%f\n",pDouble,10*sizeof(double),*pDouble);
    MEM_check_mem_block();

    MEM_free(pInt);
    MEM_check_mem_block();

    pDouble = MEM_malloc(10*sizeof(double));
    printf("addr:%p,size:%ld,value:%f\n",pDouble,10*sizeof(double),*pDouble);
    MEM_check_mem_block();

    pDouble = MEM_malloc(10*sizeof(double));
    printf("addr:%p,size:%ld\n",pDouble,10*sizeof(double));
    MEM_check_mem_block();

    MEM_free_all();
    MEM_check_mem_block();

    return 0;
}