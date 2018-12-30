#pragma once
#include "../syntaxtree.hpp"
#include <string>
#include <regex>
#include <sstream>

namespace littl {
    class LittlInt : public SyntaxTree{
        public:
            LittlInt(const std::string& val){
                value = std::stoi(std::regex_replace(std::regex_replace(val, std::regex("\\)"), ""), std::regex("\\("), ""));
            }
            virtual ~LittlInt() = default;
            virtual std::string toCode() const{
                if(value < 0){
                    return "(" + std::to_string(value) + ")";
                }

                return std::to_string(value);
            }

        private:
            int value;
    };
}