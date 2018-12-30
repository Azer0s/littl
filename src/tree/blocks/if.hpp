#pragma once
#include "../syntaxtree.hpp"

namespace littl {
    class If : public SyntaxTree{
        public:
            If(SyntaxTree* condition, SyntaxTree* block){
                this->condition = condition;
                this->block = block;
            }
            virtual ~If(){
                delete condition;
                delete block;
            };
            virtual std::string toCode() const{
                std::string code = "if(" + condition->toCode() + "){\n" + block->toCode() + "}\n";
                return code;
            }

        private:
            SyntaxTree* condition;
            SyntaxTree* block;
    };
}