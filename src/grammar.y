%{
    #include <math.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include "../src/tree/nodes.hpp"
    #include <iostream>
    #include <vector>
    #include <memory>
    extern int yylineno;
    extern char* yytext;

    int yylex(void);
    void yyerror (char const *str) {
        fprintf(stderr,"Error | Line: %d\n%s\n%s\n",yylineno,str,yytext);
    }

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
%token COMMA

%token ADD
%token SUB
%token MUL
%token DIV

%token SMALLER
%token BIGGER
%token SMALLEREQUALS
%token BIGGEREQUALS

%token EQUALS
%token NOT

%token OR
%token AND
%token IN

%token LBRACE
%token RBRACE

%token LBRACKET
%token RBRACKET

%token LSQUARE
%token RSQUARE

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
    assignment { $$ = $1; }
    | statement { $$ = new littl::Terminated($1); }
    | variable { $$ = $1; }
    | return { $$ = $1; }
    | function { $$ = $1; }
    | if { $$ = $1; }
    | for {$$ = $1; }
    | block block { $$ = new littl::Tuple($1,$2); }
    | %empty { $$ = new littl::Empty(); }
    ;

assignment:
    name ASSIGN singleValue { $$ = new littl::Assignment($1,$3); }
    ;

statement:
    name LBRACKET parameters RBRACKET { $$ = new littl::Call($1,$3); }
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

//Every block I can return - todo wrap in function
returnableBlocks:
    function { $$ = $1; }
    | if { $$ = $1; }
    ;

function:
    name arguments LBRACE block RBRACE { $$ = new littl::Function($1,$2,$4); }
    ;

if:
    IF singleValue LBRACE block RBRACE { $$ = new littl::If($2,$4); }
    ;

for:
    FOR name IN name LBRACE block RBRACE { $$ = new littl::For($2,$4,$6); }
    ;

singleValue:
    calculation { $$ = $1; }
    | literal { $$ = $1; }
    | statement { $$ = $1; }
    | name { $$ = $1; }
    ;

calculation:
    singleValue ADD singleValue { $$ = new littl::Calculation($1,"+",$3); }
    | singleValue SUB singleValue { $$ = new littl::Calculation($1,"-",$3); }
    | singleValue MUL singleValue { $$ = new littl::Calculation($1,"*",$3); }
    | singleValue DIV singleValue { $$ = new littl::Calculation($1,"/",$3); }
    | singleValue SMALLER singleValue { $$ = new littl::Calculation($1,"<",$3); }
    | singleValue BIGGER singleValue { $$ = new littl::Calculation($1,">",$3); }
    | singleValue SMALLEREQUALS singleValue { $$ = new littl::Calculation($1,"<=",$3); }
    | singleValue BIGGEREQUALS singleValue { $$ = new littl::Calculation($1,">=",$3); }
    | singleValue EQUALS singleValue { $$ = new littl::Calculation($1,"==",$3); }
    | singleValue NOT singleValue { $$ = new littl::Calculation($1,"!=",$3); }
    | singleValue OR singleValue { $$ = new littl::Calculation($1,"||",$3); }
    | singleValue AND singleValue { $$ = new littl::Calculation($1,"&&",$3); }
    | LBRACKET calculation RBRACKET { $$ = new littl::Bracket($2); }
    ;

parameters:
    singleValue { $$ = $1; }
    | parameters COMMA singleValue { $$ =  new littl::Arguments($1,$3); }
    ;

arguments:
    name arguments { $$ = new littl::Arguments($1,$2); }
    | name { $$ = $1; }
    | %empty { $$ = new littl::Empty(); }
    ;

literal:
    DECIMAL { $$ = new littl::LittlDec(yytext); }
    | INT { $$ = new littl::LittlInt(yytext); }
    | BOOL { $$ = new littl::LittlBool(yytext); }
    | STRING { $$ = new littl::LittlString(yytext); }
    | array { $$ = $1; }
    ;

array:
    LBRACE RBRACE { $$ = new littl::Array(new littl::Empty()); }
    | LBRACE parameters RBRACE { $$ = new littl::Array($2); }
    ;

name:
    name LSQUARE singleValue RSQUARE { $$ = new littl::ArrayAccess($1,$3); } 
    | NAME { $$ = new littl::Name(yytext); }
    ;
