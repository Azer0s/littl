#pragma once
#include "../syntaxtree.hpp"

namespace littl {
    class Variable : public SyntaxTree{
        public:
            Variable(SyntaxTree* varname, bool constant, SyntaxTree* value){
                this->constant = constant;
                this->varname = varname;
                this->value = value;
            }
            virtual ~Variable(){
                delete varname;
                delete value;
            };
            virtual std::string toCode() const{
                std::string x; 
                if(constant){
                    x = "const ";
                }else{
                    x = "var ";
                }
                x += varname->toCode() + " = " + value->toCode() + ";\n";
                return x;
            }

        private:
            SyntaxTree* varname;
            bool constant;
            SyntaxTree* value;
    };
}