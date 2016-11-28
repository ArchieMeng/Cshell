//
// Created by archie on 16-10-14.
//

#ifndef CREATE
#define CREATE

#include "cshell.h"
#include "expression.h"

Expression* csm_alloc_expression(ExpressionType type)
{
    Expression *exp;
    exp = MEM_malloc(sizeof(Expression));
    exp->type = type;
}

Expression* csm_create_identifier_expression(char *identifier)
{
    Expression *exp;
    exp = csm_alloc_expression(IDENTIFIER_EXPRESSION);
    exp->u.identifier = identifier;

    return exp;
}

Expression* csm_create_binary_expression(Expression *left, ExpressionType operator, Expression *right)
{
    Expression *exp;
    exp = csm_alloc_expression(BINARY_EXPRESSION);
    exp->u.binary_expression.left = left;
    exp->u.binary_expression.operator = operator;
    exp->u.binary_expression.right = right;
    return exp;
}

Expression* create_function_call_expression(char *function_name, ParameterList *parameterList)
{
    Expression *exp;
    exp = csm_alloc_expression(FUNCTION_CALL_EXPRESSION);
    exp->u.function_call_expression.function_name = function_name;
    exp->u.function_call_expression.parameterList = parameterList;
    return exp;
}

Expression* csm_create_assign_expression(char *identifier, Expression *expression)
{
    Expression *exp;
    exp = csm_alloc_expression(ASSIGN_EXPRESSION);
    exp->u.assign_expression.variable = identifier;
    exp->u.assign_expression.right = expression;
    return exp;
}



#endif
