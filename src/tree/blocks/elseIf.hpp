#pragma once
#include "../syntaxtree.hpp"

namespace littl {
    class ElseIf : public SyntaxTree{
        public:
            ElseIf(SyntaxTree* condition, SyntaxTree* block){
                this->condition = condition;
                this->block = block;
            }
            virtual ~ElseIf(){
                delete condition;
                delete block;
            };
            virtual std::string toCode() const{
                return "else if(" + condition->toCode() + "){\n" + block->toCode() + "}\n";
            }

        private:
            SyntaxTree* condition;
            SyntaxTree* block;
    };
}