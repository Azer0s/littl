#pragma once
#include "../syntaxtree.hpp"

namespace littl {
    class Returnable : public SyntaxTree{
        public:
            Returnable(SyntaxTree* block){
                this->block = block;
            }
            virtual ~Returnable(){
                delete block;
            };
            virtual std::string toCode() const{
                std::string code = "function(){\n" + block->toCode() + "}\n";
                return code;
            }

        private:
            SyntaxTree* block;
    };
}