#pragma once
#include "../syntaxtree.hpp"

namespace littl {
    class Return : public SyntaxTree{
        public:
            Return(SyntaxTree* val){
                this->val = val;
            }
            virtual ~Return(){
                delete val;
            };
            virtual std::string toCode() const{
                return "return " + val->toCode() + ";\n";
            }

        private:
            SyntaxTree* val;
    };
}