#pragma once
#include "../syntaxtree.hpp"

namespace littl {
    class CountedFor : public SyntaxTree{
        public:
            CountedFor(SyntaxTree* var, SyntaxTree* condition, SyntaxTree* op, SyntaxTree* block){
                this->var = var;
                this->condition = condition;
                this->op = op;
                this->block = block;
            }
            virtual ~CountedFor(){
                delete var;
                delete condition;
                delete op;
                delete block;
            };
            virtual std::string toCode() const{
                return "for(" + var ->toCode() + condition->toCode() + ";" + op->toCode() + "){\n" + block->toCode() + "}\n";
            }

        private:
            SyntaxTree* var;
            SyntaxTree* condition;
            SyntaxTree* op;
            SyntaxTree* block;
    };
}