//
// Created by archie on 16-11-8.
//

#ifndef CSHELL_EXPRESSION_H
#define CSHELL_EXPRESSION_H

#include "cshell.h"

typedef struct IdentifierList_tag{
    char *identifier;
    IdentifierList next;
}IdentifierList;

typedef struct Expression_tag Expression;
typedef struct ParameterList_tag ParameterList;

typedef enum {
    BOOLEAN_EXPRESSION = 1,
    INT_EXPRESSION,
    DOUBLE_EXPRESSION,
    STRING_EXPRESSION,
    BINARY_EXPRESSION,
    IDENTIFIER_EXPRESSION,
    ASSIGN_EXPRESSION,
    ADD_EXPRESSION,
    SUB_EXPRESSION,
    MUL_EXPRESSION,
    DIV_EXPRESSION,
    MOD_EXPRESSION,
    EQ_EXPRESSION,
    NE_EXPRESSION,
    GT_EXPRESSION,
    GE_EXPRESSION,
    LT_EXPRESSION,
    LE_EXPRESSION,
    LOGICAL_AND_EXPRESSION,
    LOGICAL_OR_EXPRESSION,
    MINUS_EXPRESSION,
    FUNCTION_CALL_EXPRESSION,
    NULL_EXPRESSION,
    EXPRESSION_TYPE_COUNT_PLUS_1
}   ExpressionType;

typedef struct {
    Expression *left;
    ExpressionType operator;
    Expression *right;
}   BinaryExpression;

typedef struct {
    char *variable;
    Expression *right;
}   AssignExpression;

typedef struct {
    char *function_name;
    ParameterList *parameterList;
}   FunctionCallExpression;

struct Expression_tag{
    ExpressionType type;
    int line_number;
    union {
        CSM_Boolean boolean_value;
        int int_value;
        double double_value;
        char *string_value;
        char *identifier;
        AssignExpression assign_expression;
        BinaryExpression binary_expression;
        Expression *expression;
        FunctionCallExpression function_call_expression;
    }   u;
};

Expression* csm_alloc_expression(ExpressionType type);
Expression* csm_create_identifier_expression(char *name);
Expression* csm_create_binary_expression(Expression *left, ExpressionType operator, Expression *right);
Expression* csm_create_function_call_expression(char *function_name, ParameterList *parameterList);
Expression* csm_create_assign_expression(char *identifier,Expression *expression);

#endif //CSHELL_EXPRESSION_H
