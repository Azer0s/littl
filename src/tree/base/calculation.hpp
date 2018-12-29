#pragma once
#include <vector>
#include <string>
#include <memory>
#include "../syntaxtree.hpp"

namespace littl {
    class Calculation : public SyntaxTree{
        public:
            Calculation(SyntaxTree* op1, std::string operation, SyntaxTree* op2){
                this->op1 = op1;
                this->op2 = op2;
                this->operation = operation;
            };
            virtual ~Calculation(){
                delete op1;
                delete op2;
            };
            virtual std::string toCode() const{
                return op1->toCode() + operation + op2->toCode();
            };

        private:
            SyntaxTree* op1;
            SyntaxTree* op2;
            std::string operation;
    };
}