#pragma once
#include "../syntaxtree.hpp"

namespace littl {
    class Import : public SyntaxTree{
        public:
            Import(SyntaxTree* name){
                this->name = name;
            }
            virtual ~Import(){
                delete name;
            };
            virtual std::string toCode() const{
                return "";
            }

        private:
            SyntaxTree* name;
    };
}