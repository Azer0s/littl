#pragma once
#include <vector>
#include <string>
#include <memory>
#include "../syntaxtree.hpp"

namespace littl {
    class Arguments : public SyntaxTree{
        public:
            Arguments(SyntaxTree* val, SyntaxTree* vals){
                tree = val;
                subtree = vals;
            };
            virtual ~Arguments(){
                delete tree;
                delete subtree;
            };
            virtual std::string toCode() const{
                return tree->toCode() + "," + subtree->toCode();
            };

        private:
            SyntaxTree* tree;
            SyntaxTree* subtree;
    };
}