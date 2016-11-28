//
// Created by archie on 16-10-14.
//

#ifndef EXECUTE
#define EXECUTE

#include "CSM.h"
#include <stdio.h>

void CSM_interpret(CSM_Interpreter *interpreter)
{
    interpreter->execute_storage = MEM_open_storage(0);
    csm_add_std_fp(interpreter);
    csm_execute_statement_list(interpreter, NULL, interpreter->statement_list);
}

//Todo complete expression execution

#endif