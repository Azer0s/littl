#pragma once
#include "../syntaxtree.hpp"
#include <string>
#include <sstream>

namespace littl {
    class LittlString : public SyntaxTree{
        public:
            LittlString(const std::string& val){
                value = val;
            }
            virtual ~LittlString() = default;
            virtual std::string toCode() const{
                return value;
            }

        private:
            std::string value;
    };
}