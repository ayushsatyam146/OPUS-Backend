#include "tokenizer.hpp"
#include<iostream>
#include<fstream>

using namespace std;
using namespace simpleParser;

int main() {
    std::ifstream t("C:\\Users\\ayush\\Desktop\\COMPILER_PROJ_C++\\src.txt");
    t.seekg(0, std::ios::end);
    size_t size = t.tellg();
    std::string fileContents(size, ' ');
    t.seekg(0);
    t.read(&fileContents[0], size); 

    cout << fileContents;
    tokenizer lexer; 
    vector<Token> tokens = lexer.parse(fileContents);

    for (Token token : tokens) {
        token.debugPrint();
    }
}

