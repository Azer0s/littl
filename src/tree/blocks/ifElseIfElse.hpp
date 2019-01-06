#pragma once
#include "../syntaxtree.hpp"

namespace littl {
    class IfElseIfElse : public SyntaxTree{
        public:
            IfElseIfElse(SyntaxTree* condition, SyntaxTree* block, SyntaxTree* elseIfBlock, SyntaxTree* elseBlock){
                this->condition = condition;
                this->block = block;
                this->elseIfBlock = elseIfBlock;
                this->elseBlock = elseBlock;
            }
            virtual ~IfElseIfElse(){
                delete condition;
                delete block;
                delete elseIfBlock;
                delete elseBlock;
            };
            virtual std::string toCode() const{
                return "if(" + condition->toCode() + "){\n" + block->toCode() + "}\n" + elseIfBlock->toCode() + "else{\n" + elseBlock->toCode() + "}\n";
            }

        private:
            SyntaxTree* condition;
            SyntaxTree* block;
            SyntaxTree* elseIfBlock;
            SyntaxTree* elseBlock;
    };
}