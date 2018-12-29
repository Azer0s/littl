%option noyywrap

%{
    #include "grammar.tab.h"
%}

INT                             [1-9][0-9]*
DECIMAL                         INT\.[0-9]+
STRING                          \"[^\n"]*\"
BOOL                            true|false

NAME                            [a-zA-Z][a-zA-Z0-9._]*

VAR                             var
CONST                           var!
ANONYMOUS                       anonymous

IF                              if
FOR                             for
PUT                             put

ASSIGN                          "="
SHORTHANDASSIGN                 ":="
SEMICOLON                       ";"
COMMA                           ","

WHITESPACE                      [ \r\t\v\f]
FEED                            \n

%%

{STRING}                        return STRING;
{INT}                           return INT;
{DECIMAL}                       return DECIMAL;
{BOOL}                          return BOOL;

{VAR}                           return VAR;
{CONST}                         return CONST;
{ANONYMOUS}                     return ANONYMOUS;

{IF}                            return IF;
{FOR}                           return FOR;
{PUT}                           return PUT;

{ASSIGN}                        return ASSIGN;
{SHORTHANDASSIGN}               return SHORTHANDASSIGN;
{SEMICOLON}                     return SEMICOLON;
{COMMA}                         return COMMA;

{NAME}                          return NAME;
{WHITESPACE}

{FEED}                          yylineno++;
%%