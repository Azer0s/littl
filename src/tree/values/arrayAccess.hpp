#pragma once
#include "../syntaxtree.hpp"

namespace littl {
    class ArrayAccess : public SyntaxTree{
        public:
            ArrayAccess(SyntaxTree* name,SyntaxTree* index){
                this->name = name;
                this->index = index;
            }
            virtual ~ArrayAccess(){
                delete name;
                delete index;
            };
            virtual std::string toCode() const{
                return name->toCode() + "[" + index->toCode() + "]";
            }

        private:
            SyntaxTree* name;
            SyntaxTree* index;
    };
}