#pragma once
#include "../syntaxtree.hpp"

namespace littl {
    class IfElseIf : public SyntaxTree{
        public:
            IfElseIf(SyntaxTree* condition, SyntaxTree* block, SyntaxTree* elseIfBlock){
                this->condition = condition;
                this->block = block;
                this->elseIfBlock = elseIfBlock;
            }
            virtual ~IfElseIf(){
                delete condition;
                delete block;
                delete elseIfBlock;
            };
            virtual std::string toCode() const{
                return "if(" + condition->toCode() + "){\n" + block->toCode() + "}\n" + elseIfBlock->toCode();
            }

        private:
            SyntaxTree* condition;
            SyntaxTree* block;
            SyntaxTree* elseIfBlock;
    };
}