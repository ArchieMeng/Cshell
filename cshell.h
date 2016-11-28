#ifndef CSHELL_H_INCLUDED
#define CSHELL_H_INCLUDED

#include "CSM_dev.h"
#include "expression.h"
#include "string.h"

typedef struct Variable_tag Variable;
typedef struct FunctionDefinition_tag FunctionDefinition;
typedef struct StatementList_tag StatementList;
typedef struct Statement_tag Statement;
typedef struct Block_tag Block;
typedef struct ParameterList_tag ParameterList;

struct CSM_Interpreter_tag{
    MEM_Storage interpreter_storage;
    MEM_Storage execute_storage;
    Variable *variable;
    FunctionDefinition *function_list;
    StatementList *statement_list;
    int current_line_number;
};

struct Variable_tag{
    char *name;
    CSM_Value value;
    struct Variable_tag *next;
};

typedef enum{
    CSHELL_FUNCTION_DEFINITION = 1, /* cshell fuction type */
    NATIVE_FUNCTION_DEFINITION, /* built-in function type */
} FunctionDefinitionType;

struct FunctionDefinition_tag{
    char    *name; /* function name */
    FunctionDefinitionType  type; /* function type */

    union{
        struct {
            ParameterList   *parameter; /* parameter definition */
            Block   *block; /* function body */
        } cshell_f;
        struct{
            CSM_NativeFunctionProc  *proc;
        } native_f;
    } u;
    struct  FunctionDefinition_tag  *next;
};

struct ParameterList_tag{
    char *name;
    struct ParameterList_tag *next;
};

typedef struct {
    IdentifierList      *identifier_list;
} GlobalStatement;

typedef struct Elsif_tag {
    Expression  *condition;
    Block       *block;
    struct Elsif_tag    *next;
} Elsif;

typedef struct {
    Expression  *condition;
    Block       *then_block;
    Elsif       *elsif_list;
    Block       *else_block;
} IfStatement;

typedef struct {
    Expression  *condition;
    Block       *block;
} WhileStatement;

typedef struct {
    Expression  *init;
    Expression  *condition;
    Expression  *post;
    Block       *block;
} ForStatement;

typedef struct {
    Expression *return_value;
} ReturnStatement;

typedef enum {
    EXPRESSION_STATEMENT = 1,
    GLOBAL_STATEMENT,
    IF_STATEMENT,
    WHILE_STATEMENT,
    FOR_STATEMENT,
    RETURN_STATEMENT,
    BREAK_STATEMENT,
    CONTINUE_STATEMENT,
    STATEMENT_TYPE_COUNT_PLUS_1
} StatementType;

struct Statement_tag {
    StatementType       type;
    int                 line_number;
    union {
        Expression      *expression_s;
        GlobalStatement global_s;
        IfStatement     if_s;
        WhileStatement  while_s;
        ForStatement    for_s;
        ReturnStatement return_s;
    } u;
};

struct StatementList_tag {
    Statement   *statement;
    struct StatementList_tag    *next;
};

struct Block_tag{
    StatementList *statement_list;
};

#endif // CSHELL_H_INCLUDED
