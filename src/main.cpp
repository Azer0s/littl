#include <iostream>
#include <fstream>
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
    outputfile.open ("bin/main.js");
    outputfile << root->toCode();
    outputfile.close();

    std::cout << "Lines in source file: " << yylineno << std::endl;

    return result;
}