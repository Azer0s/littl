%option noyywrap
%option yylineno

%{
    #include "grammar.tab.h"
%}

INT                             [1-9][0-9]*
DECIMAL                         [1-9][0-9]*\.[0-9]+
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

LBRACE                          "{"
RBRACE                          "}"

LBRACKET                        "("
RBRACKET                        ")"

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
{SEMICOLON}                     return SEMICOLON;
{COMMA}                         return COMMA;

{ADD}                           return ADD;
{SUB}                           return SUB;
{MUL}                           return MUL;
{DIV}                           return DIV;

{LBRACE}                        return LBRACE;
{RBRACE}                        return RBRACE;

{LBRACKET}                      return LBRACKET;
{RBRACKET}                      return RBRACKET;

{NAME}                          return NAME;
{WHITESPACE}

{FEED}                          yylineno++;
%%