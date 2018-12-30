%option noyywrap
%option yylineno

%{
    #include "grammar.tab.h"
%}

INT                             [0-9]*
DECIMAL                         [0-9]*\.[0-9]+
STRING                          \"[^\n"]*\"
BOOL                            true|false

NAME                            [a-zA-Z][a-zA-Z0-9._]*

VAR                             var
CONST                           var!

IF                              if
FOR                             for
RETURN                          return

ASSIGN                          "="
SHORTHANDASSIGN                 ":="
SEMICOLON                       ";"
COMMA                           ","

ADD                             "+"
SUB                             "-"
MUL                             "*"
DIV                             "/"

SMALLER                         "<"
BIGGER                          ">"
SMALLEREQUALS                   "<="
BIGGEREQUALS                    ">="

EQUALS                          is
NOT                             not

OR                              or
AND                             and
IN                              in

LBRACE                          "{"
RBRACE                          "}"

LBRACKET                        "("
RBRACKET                        ")"

LSQUARE                         "["
RSQUARE                         "]"

WHITESPACE                      [ \r\t\v\f]
FEED                            \n

%%

{STRING}                        return STRING;
{INT}                           return INT;
{DECIMAL}                       return DECIMAL;
{BOOL}                          return BOOL;

{VAR}                           return VAR;
{CONST}                         return CONST;

{IF}                            return IF;
{FOR}                           return FOR;
{RETURN}                        return RETURN;

{ASSIGN}                        return ASSIGN;
{SHORTHANDASSIGN}               return SHORTHANDASSIGN;
{COMMA}                         return COMMA;

{ADD}                           return ADD;
{SUB}                           return SUB;
{MUL}                           return MUL;
{DIV}                           return DIV;

{SMALLER}                       return SMALLER;
{BIGGER}                        return BIGGER;
{SMALLEREQUALS}                 return SMALLEREQUALS;
{BIGGEREQUALS}                  return BIGGEREQUALS;

{EQUALS}                        return EQUALS;
{NOT}                           return NOT;

{OR}                            return OR;
{AND}                           return AND;
{IN}                            return IN;

{LBRACE}                        return LBRACE;
{RBRACE}                        return RBRACE;

{LBRACKET}                      return LBRACKET;
{RBRACKET}                      return RBRACKET;

{LSQUARE}                       return LSQUARE;
{RSQUARE}                       return RSQUARE;

{NAME}                          return NAME;
{WHITESPACE}

{FEED}                          yylineno++;
%%