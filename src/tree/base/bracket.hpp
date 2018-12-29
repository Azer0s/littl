#pragma once
#include <vector>
#include <string>
#include <memory>
#include "../syntaxtree.hpp"

namespace littl {
    class Bracket : public SyntaxTree{
        public:
            Bracket(SyntaxTree* calculation){
                this->calculation = calculation;
            };
            virtual ~Bracket(){
                delete calculation;
            };
            virtual std::string toCode() const{
                return "(" + calculation->toCode() + ")";
            };

        private:
            SyntaxTree* calculation;
    };
}