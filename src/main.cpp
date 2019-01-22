#include <iostream>
#include <fstream>
#include <regex>
#include "tree/nodes.hpp"

extern int yyparse();
extern int yylex();
extern int yylineno;
extern littl::SyntaxTree* root;

int main(){
    int result = yyparse();

    if(result == 0){
        std::cout << "Input is valid!" << std::endl;
    }else{
        std::cout << "Input invalid!" << std::endl;
    }

    std::ofstream outputfile;
    outputfile.open ("out.js");

    std::string code = "//littl compiler output\n//Copyright 2018-present Ariel Simulevski\n";
    code +=  root->toCode();
    outputfile << code;
    outputfile.close();

    std::cout << "Lines in source file: " << yylineno << std::endl;

    return result;
}