#pragma once
#include "../syntaxtree.hpp"

namespace littl {
    class IfElse : public SyntaxTree{
        public:
            IfElse(SyntaxTree* condition, SyntaxTree* block, SyntaxTree* elseBlock){
                this->condition = condition;
                this->block = block;
                this->elseBlock = elseBlock;
            }
            virtual ~IfElse(){
                delete condition;
                delete block;
                delete elseBlock;
            };
            virtual std::string toCode() const{
                return "if(" + condition->toCode() + "){\n" + block->toCode() + "}\nelse{\n" + elseBlock->toCode() + "}\n";
            }

        private:
            SyntaxTree* condition;
            SyntaxTree* block;
            SyntaxTree* elseBlock;
    };
}