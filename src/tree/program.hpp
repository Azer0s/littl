#pragma once
#include <vector>
#include <string>
#include <memory>
#include "nodes.hpp"

namespace littl {
    class Program : public SyntaxTree {
        public:
            Program(std::vector<SyntaxTree*> val, SyntaxTree* vals){
                mainobject = val;
                subtree = vals;
            };
            virtual ~Program(){
                delete subtree;

                for(SyntaxTree* node : mainobject){
                    delete node;
                }
            };
            virtual std::string toCode() const{
                std::string program;
                program += "#include <string>\n";
                program += "#include <iostream>\n";
                program += "#define out(a) std::cout << a <<std::endl\n";
                program += "std::string in(){ std::string val; std::getline(std::cin,val); return val;}\n";

                program += subtree->toCode();


                program += "int main(){\n";
                for(SyntaxTree* node : mainobject){
                    program += node->toCode();
                }
                program += "}";

                return program;
            };
        private:
            std::vector<SyntaxTree*> mainobject;
            SyntaxTree* subtree;
    };
}