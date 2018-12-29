#pragma once
#include "../syntaxtree.hpp"

namespace littl {
    class Call : public SyntaxTree{
        public:
            Call(SyntaxTree* name,SyntaxTree* args){
                this->name = name;
                this->args = args;
            }
            virtual ~Call(){
                delete name;
                delete args;
            };
            virtual std::string toCode() const{
                return name->toCode() + "(" + args->toCode() + ");\n";
            }

        private:
            SyntaxTree* name;
            SyntaxTree* args;
    };
}