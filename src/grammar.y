%{
    #include <math.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include "../src/tree/nodes.hpp"
    #include <iostream>
    #include <vector>
    #include <memory>
    extern int yylineno;
    int yylex(void);
    void yyerror (char const *str) {
        fprintf(stderr,"Error | Line: %d\n%s\n",yylineno,str);
    }
    extern char* yytext;

    littl::SyntaxTree* root;
    littl::SyntaxTree* p;
    std::vector<littl::SyntaxTree*> tree;
    #define YYSTYPE littl::SyntaxTree*
%}

%locations

%token INT
%token DECIMAL
%token STRING
%token BOOL

%token VAR
%token CONST

%token IF
%token FOR
%token RETURN

%token ASSIGN
%token SHORTHANDASSIGN
%token SEMICOLON
%token COMMA

%token ADD
%token SUB
%token MUL
%token DIV

%token LBRACE
%token RBRACE

%token LBRACKET
%token RBRACKET

%token NAME

%start input

%%

input:
    program { root = new littl::Program(tree); }
    ;

program:
    block program { tree.insert(tree.begin(),$1); }
    | %empty { $$ = new littl::Empty();}
    ;

block:
    | variable { $$ = $1; }
    | return { $$ = $1; }
    | returnableBlocks { $$ = $1; }
    | statement { $$ = $1; }
    | block block { $$ = new littl::Tuple($1,$2); }
    | %empty { $$ = new littl::Empty(); }
    ;

variable:
    CONST name ASSIGN singleValue { $$ = new littl::Variable($2,true,$4); }
    | VAR name ASSIGN singleValue { $$ = new littl::Variable($2,false,$4); }
    | name SHORTHANDASSIGN singleValue { $$ = new littl::Variable($1,false,$3); }
    ;

return:
    RETURN singleValue { $$ = new littl::Return($2); }
    | RETURN returnableBlocks { $$ = new littl::Return($2); }
    ;

//Every block I can return 
returnableBlocks:
    function { $$ = $1; }
    ;

statement:
    name LBRACKET parameters RBRACKET { $$ = new littl::Call($1,$3); }
    ;

parameters:
    singleValue { $$ = $1; }
    | parameters COMMA singleValue { $$ =  new littl::Arguments($1,$3); }
    ;

singleValue:
    literal { $$ = $1; }
    | name { $$ = $1; }
    | statement { $$ = $1; }
    | calculation { $$ = $1; }
    ;

calculation:
    singleValue ADD singleValue { $$ = new littl::Calculation($1,"+",$3); }
    | singleValue SUB singleValue { $$ = new littl::Calculation($1,"-",$3); }
    | singleValue MUL singleValue { $$ = new littl::Calculation($1,"*",$3); }
    | singleValue DIV singleValue { $$ = new littl::Calculation($1,"/",$3); }
    | LBRACKET calculation RBRACKET { $$ = new littl::Bracket($2); }
    ;

function:
    name arguments LBRACE block RBRACE { $$ = new littl::Function($1,$2,$4); }
    ;

arguments:
    name arguments { $$ = new littl::Arguments($1,$2); }
    | name { $$ = $1; }
    | %empty { $$ = new littl::Empty();}
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