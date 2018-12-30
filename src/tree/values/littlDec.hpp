#pragma once
#include "../syntaxtree.hpp"
#include <string>
#include <regex>
#include <sstream>

namespace littl {
    class LittlDec : public SyntaxTree{
        public:
            LittlDec(const std::string& val){
                value = std::stod(std::regex_replace(std::regex_replace(val, std::regex("\\)"), ""), std::regex("\\("), ""));
            }
            virtual ~LittlDec() = default;
            virtual std::string toCode() const{
                if(value < 0){
                    return "(" + std::to_string(value) + ")";
                }

                return std::to_string(value);
            }

        private:
            double value;
    };
}