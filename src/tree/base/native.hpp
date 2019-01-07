#pragma once
#include <string>
#include <regex>
#include "../syntaxtree.hpp"

namespace littl {
    class Native : public SyntaxTree{
        public:
            Native(const std::string& name){
                std::regex str("^.(.*)..$");
                const char* c = name.c_str();
                std::cmatch cm;
                std::regex_match(c,cm,str,std::regex_constants::match_default);
                this->name = cm[1];
            }
            virtual ~Native() = default;
            virtual std::string toCode() const{
                return name;
            }

        private:
            std::string name;
    };
}