#pragma once
#include <vector>
#include <string>
#include <memory>
#include "../syntaxtree.hpp"

namespace littl {
    class Assignment : public SyntaxTree{
        public:
            Assignment(SyntaxTree* val, SyntaxTree* vals){
                tree = val;
                subtree = vals;
            };
            virtual ~Assignment(){
                delete tree;
                delete subtree;
            };
            virtual std::string toCode() const{
                return tree->toCode() + "=" + subtree->toCode() + ";\n";
            };

        private:
            SyntaxTree* tree;
            SyntaxTree* subtree;
    };
}