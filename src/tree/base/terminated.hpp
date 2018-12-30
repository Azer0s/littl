#pragma once
#include "../syntaxtree.hpp"

namespace littl {
    class Terminated : public SyntaxTree{
        public:
            Terminated(SyntaxTree* val){
                this->val = val;
            }
            virtual ~Terminated(){
                delete val;
            };
            virtual std::string toCode() const{
                return val->toCode() + ";\n";
            }

        private:
            SyntaxTree* val;
    };
}