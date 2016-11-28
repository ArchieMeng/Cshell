#ifndef CSM_H_INCLUDED
#define CSM_H_INCLUDED

#include <stdio.h>
#include"cshell.h"
#include "MEM.h"

typedef struct CSM_Interpreter_tag CSM_Interpreter;

CSM_Interpreter* CSM_create_interpreter(void);
void CSM_compile(CSM_Interpreter *interpreter, FILE *fp);
void CSM_interpret(CSM_Interpreter *interpreter);
void CSM_dispose_interpreter(CSM_Interpreter *interpreter);

#endif // CSM_H_INCLUDED
