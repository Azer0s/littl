#pragma once
#include "../syntaxtree.hpp"

namespace littl {
    class LittlBool : public SyntaxTree{
        public:
            LittlBool(const std::string& val){
                if(val == "true"){
                    value = true;
                }else{
                    value = false;
                }
            }
            virtual ~LittlBool() = default;
            virtual std::string toCode() const{
                return value ? "true" : "false";;
            }

        private:
            bool value;
    };
}