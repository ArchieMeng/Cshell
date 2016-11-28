%{
#include"cshell.h"
%}

%start COMMENT STRING_LITERAL_STATE

%%
<INITIAL>"function" return FUNCTION;
<INITIAL>"if" return IF;
<INITIAL>"else if" return ELIF;
<INITIAL>"else" return ELSE;
<INITIAL>"while" return WHILE;
<INITIAL>"for" return FOR;

<INITIAL>"(" return LP;
<INITIAL>")" return RP;
<INITIAL>"{" return LC;
<INITIAL>"}" return RC;
<INITIAL>"+" return ADD;
<INITIAL>"-" return SUB;
<INITIAL>"*" return MUL;
<INITIAL>"/" return DIV;
<INITIAL>"=" return ASSIGN;
<INITIAL>"==" return EQ;
<INITIAL>"<" return LT;
<INITIAL>">" return GT;
<INITIAL>"<=" return LE;
<INITIAL>">=" return GE;
<INITIAL>"!=" return NE;
<INITIAL>"&&" return AND;
<INITIAL>"||" return OR;
<INITIAL>"&" return ADO;
<INITIAL>"|" return ORO;
<INITIAL>"^" return NORO;
<INITIAL>"!" return NOT;
<INITIAL>"~" return NOTO;


<INITIAL>[a-zA-Z_][a-zA-Z_0-9]*
{
  yylval.identifier = csm_create_identifier(yytext);
  return IDENTIFIER;
}

<INITIAL>([1-9][0-9]*)|"0"
{
  Expression *expression = csm_alloc_expression(INT_EXPRESSION);
  sscanf(yytext,"%d",&expression->u.int_value);
  yylval.expression = expression;
  return INT_LITERAL;
}

<INITIAL>[0-9]+\.[0-9]+
{
  Expression *expression = csm_alloc_expression(DOUBLE_EXPRESSION);
  sscanf(yytext,"%lf",&expression->u.double_value);
  yylval.expression = expression;
  return DOUBLE_LITERAL;
}

<INITIAL>\"
{
  csm_open_string_literal();
  BEGIN STRING_LITERAL_STATE;
} 

<INITIAL>[ \t\r];
<INITIAL>\n
{
  increment_line_number();
}

<INITIAL># BEGIN COMMENT;

<INITIAL>.
{
  char buf[LINE_BUF_SIZE];
  if( isprint(yytext[0]) )
  {
    buf[0] = yytext[0];
    buf[1] = '\0';
  }
  else
  {
    sprintf(buf,"0x%02x",(unsigned char)yytext[0]);
  }
  csm_compile_error(CHARACTER_INVALID_ERR, STRING_MESSAGE_ARGUMENT, "bad_char", buf, MESSAGE_ARGUMENT_END);
}

<COMMENT>\n
{
  increment_line_number();
  BEGIN INITIAL;
}

<COMMENT>. ;
<STRING_LITERAL_STATE>\"
{
  Expression *expression = csm_alloc_expression(STRING_EXPRESSION);
  expression->u.string_value = csm_close_string_literal();
  yylval.expression = expression;
  BEGIN INITIAL;
}
<STRING_LITERAL_STATE>\n
{
  csm_add_string_literal('\n');
  increment_line_number();
}

<STRING_LITERAL_STATE>\\\" csm_add_string_literal('"');
<STRING_LITERAL_STATE>\\n csm_add_string_literal('\n');
<STRING_LITERAL_STATE>\\t csm_add_string_literal('\t');
<STRING_LITERAL_STATE>\\\\ csm_add_string_literal('\\');
<STRING_LITERAL_STATE>. csm_add_string_literal(yytext[0]);
%%
