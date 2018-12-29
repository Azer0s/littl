#pragma once
#include "../syntaxtree.hpp"
#include <string>
#include <sstream>

namespace littl {
    class LittlDec : public SyntaxTree{
        public:
            LittlDec(const std::string& val){
                value = std::stod(val);
            }
            virtual ~LittlDec() = default;
            virtual std::string toCode() const{
                return std::to_string(value);
            }

        private:
            double value;
    };
}