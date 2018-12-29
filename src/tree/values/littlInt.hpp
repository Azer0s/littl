#pragma once
#include "../syntaxtree.hpp"
#include <string>
#include <sstream>

namespace littl {
    class LittlInt : public SyntaxTree{
        public:
            LittlInt(const std::string& val){
                value = std::stoi(val);
            }
            virtual ~LittlInt() = default;
            virtual std::string toCode() const{
                return std::to_string(value);
            }

        private:
            int value;
    };
}