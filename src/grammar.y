%{
    #include <math.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include "../src/tree/nodes.hpp"
    #include <iostream>
    #include <vector>
    #include <memory>

    int yylex(void);
    void yyerror (char const *s) {
        fprintf (stderr, "%s\n", s);
    }
    extern char* yytext;
    littl::SyntaxTree* root;
    littl::SyntaxTree* p;
    std::vector<littl::SyntaxTree*> mainobject;
    #define YYSTYPE littl::SyntaxTree*
%}

%token INT
%token DECIMAL
%token STRING
%token BOOL

%token VAR
%token CONST
%token ANONYMOUS

%token IF
%token FOR
%token PUT

%token ASSIGN
%token SHORTHANDASSIGN
%token SEMICOLON
%token COMMA

%token NAME

%start input

%%

input:
    program { root = new littl::Program(mainobject, $1); }
    ;

program:
    block program { mainobject.push_back($1); $$ = $2; }
    | function program { $$ = new littl::Tuple($1,$2); }
    | %empty { $$ = new littl::Empty();}
    ;

function:
    ;

block:
    | variable
    | %empty
    ;

variable:
    CONST name ASSIGN literal
    | VAR name ASSIGN literal
    | name SHORTHANDASSIGN literal
    ;

literal:
    DECIMAL { $$ = new littl::LittlDec(yytext); }
    | INT { $$ = new littl::LittlInt(yytext); }
    | BOOL { $$ = new littl::LittlBool(yytext); }
    | STRING { $$ = new littl::LittlString(yytext); }
    ;

name:
    NAME { $$ = new littl::Name(yytext); }
    ;