//
// Created by archie on 16-10-14.
//

#ifndef CREATE
#define CREATE

Expression *csm_execute_calc_expression(Expression *exp);

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

Expression* csm_execute_expression(Expression *exp)
{
    Expression *result;


    switch (exp->u.binary_expression.operator)
    {
        case ADD_EXPRESSION:
        case SUB_EXPRESSION:
        case DIV_EXPRESSION:
        case MUL_EXPRESSION:
        case MOD_EXPRESSION:
            result = csm_execute_calc_expression(exp);
            return result;
        case LOGICAL_AND_EXPRESSION:
        case LOGICAL_OR_EXPRESSION:
        case GE_EXPRESSION:
        case GT_EXPRESSION:
        case LT_EXPRESSION:
        case LE_EXPRESSION:
        case EQ_EXPRESSION:
        case NE_EXPRESSION:
            result = csm_execute_logical_expression(exp);
            return result;
    }
}

Expression *csm_execute_calc_expression(Expression *exp) {
    Expression *result;
    Expression *left = exp->u.binary_expression.left, *right = exp->u.binary_expression.right;
    ExpressionType op = exp->u.binary_expression.operator;

    if (left->type == INT_EXPRESSION)
    {
        if (right->type == INT_EXPRESSION)
        {
            result = csm_alloc_expression(INT_EXPRESSION);
            switch (op)
            {
                case ADD_EXPRESSION:
                    result->u.int_value = left->u.int_value + right->u.int_value;
                    break;
                case SUB_EXPRESSION:
                    result->u.int_value = left->u.int_value - right->u.int_value;
                    break;
                case MUL_EXPRESSION:
                    result->u.int_value = left->u.int_value * right->u.int_value;
                    break;
                case DIV_EXPRESSION:
                    result->u.int_value = left->u.int_value / right->u.int_value;
                    break;
                case MOD_EXPRESSION:
                    result->u.int_value = left->u.int_value % right->u.int_value;
                    break;
            }
            return result;
        }
        else if (right->type == DOUBLE_EXPRESSION)
        {
            result = csm_alloc_expression(DOUBLE_EXPRESSION);
            switch (op)
            {
                case ADD_EXPRESSION:
                    result->u.double_value = left->u.int_value + right->u.double_value;
                    break;
                case SUB_EXPRESSION:
                    result->u.double_value = left->u.int_value - right->u.double_value;
                    break;
                case MUL_EXPRESSION:
                    result->u.double_value = left->u.int_value * right->u.double_value;
                    break;
                case DIV_EXPRESSION:
                    result->u.double_value = left->u.int_value / right->u.double_value;
                    break;
                case MOD_EXPRESSION:
                    csm_internal_error("double cannot mod int",__FILE__,__LINE__);
                    break;
            }
            return result;
        }
    }
    else
    {
        result = csm_alloc_expression(DOUBLE_EXPRESSION);
        if (right->type == INT_EXPRESSION)
        {
            switch (op)
            {
                case ADD_EXPRESSION:
                    result->u.double_value = left->u.double_value + right->u.int_value;
                    break;
                case SUB_EXPRESSION:
                    result->u.double_value = left->u.double_value - right->u.int_value;
                    break;
                case MUL_EXPRESSION:
                    result->u.double_value = left->u.double_value * right->u.int_value;
                    break;
                case DIV_EXPRESSION:
                    result->u.double_value = left->u.double_value / right->u.int_value;
                    break;
                case MOD_EXPRESSION:
                    csm_internal_error("double cannot mod int",__FILE__,__LINE__);
                    break;
            }
            return result;
        }
        else if (right->type == DOUBLE_EXPRESSION)
        {
            switch (op)
            {
                case ADD_EXPRESSION:
                    result->u.double_value = left->u.double_value + right->u.double_value;
                    break;
                case SUB_EXPRESSION:
                    result->u.double_value = left->u.double_value - right->u.double_value;
                    break;
                case MUL_EXPRESSION:
                    result->u.double_value = left->u.double_value * right->u.double_value;
                    break;
                case DIV_EXPRESSION:
                    result->u.double_value = left->u.double_value / right->u.double_value;
                    break;
                case MOD_EXPRESSION:
                    csm_internal_error("double cannot mod int",__FILE__,__LINE__);
                    break;
            }
            return result;
        }
    }
}


#endif
