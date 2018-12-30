#pragma once
#include "../syntaxtree.hpp"

namespace littl {
    class For : public SyntaxTree{
        public:
            For(SyntaxTree* var, SyntaxTree* array, SyntaxTree* block){
                this->var = var;
                this->array = array;
                this->block = block;
            }
            virtual ~For(){
                delete var;
                delete array;
                delete block;
            };
            virtual std::string toCode() const{
                return "for(" + var->toCode() + " in " + array->toCode() + "){\n" + block->toCode() + "}\n";
            }

        private:
            SyntaxTree* var;
            SyntaxTree* array;
            SyntaxTree* block;
    };
}