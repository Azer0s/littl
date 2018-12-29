#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include "nodes.hpp"

namespace littl {
    class Program : public SyntaxTree {
        public:
            Program(std::vector<SyntaxTree*> val){
                tree = val;
            };
            virtual ~Program(){
                for(SyntaxTree* node : tree){
                    delete node;
                }
            };
            virtual std::string toCode() const{
                std::string program;
                for(SyntaxTree* node : tree){
                    program += node->toCode();
                }
                return program;
            };
        private:
            std::vector<SyntaxTree*> tree;
    };
}