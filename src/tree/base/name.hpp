#pragma once
#include "../syntaxtree.hpp"

namespace littl {
    class Name : public SyntaxTree{
        public:
            Name(const std::string& name){
                this->name = name;
            }
            virtual ~Name() = default;
            virtual std::string toCode() const{
                return name;
            }

        private:
            std::string name;
    };
}