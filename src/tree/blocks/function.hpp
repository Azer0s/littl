#pragma once
#include "../syntaxtree.hpp"

namespace littl {
    class Function : public SyntaxTree{
        public:
            Function(SyntaxTree* name, SyntaxTree* input, SyntaxTree* block){
                this->name = name;
                this->input = input;
                this->block = block;
            }
            virtual ~Function(){
                delete name;
                delete input;
                delete block;
            };
            virtual std::string toCode() const{
                std::string fName;

                if(name->toCode().compare("anonymous") == 0){
                    fName = "";
                }else{
                    fName = name->toCode();
                }

                std::string code = "function " + fName + "(" + input->toCode() + "){\n" + block->toCode() + "};\n";
                return code;
            }

        private:
            SyntaxTree* name;
            SyntaxTree* input;
            SyntaxTree* block;
    };
}