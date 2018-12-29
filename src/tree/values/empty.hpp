#pragma once
#include "../syntaxtree.hpp"
#include <string>
#include <sstream>

namespace littl {
    class Empty : public SyntaxTree {
        public:
            Empty(){}
            virtual ~Empty() = default;
            virtual std::string toCode() const{
                return "";
            }
    };
}