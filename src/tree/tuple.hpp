#pragma once
#include <vector>
#include <string>
#include <memory>
#include "nodes.hpp"

namespace littl {
    class Tuple : public SyntaxTree{
        public:
            Tuple(SyntaxTree* val, SyntaxTree* vals){
                tree = val;
                subtree = vals;
            };
            virtual ~Tuple(){
                delete tree;
                delete subtree;
            };
            virtual std::string toCode() const{
                return tree->toCode() + "\n" + subtree->toCode();
            };

        private:
            SyntaxTree* tree;
            SyntaxTree* subtree;
    };
}