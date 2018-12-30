#pragma once
#include "../syntaxtree.hpp"

namespace littl {
    class Array : public SyntaxTree{
        public:
            Array(SyntaxTree* vals){
                this->vals = vals;
            }
            virtual ~Array(){
                delete vals;
            };
            virtual std::string toCode() const{
                return "[" + vals->toCode() + "]";
            }

        private:
            SyntaxTree* vals;
    };
}