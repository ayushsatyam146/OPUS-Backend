#pragma once

#include <vector>
#include <string>

namespace simpleParser{

    using namespace std;

    enum TokenType {
        WHITESPACE,  //default tpye but no token actually gets this type
        IDENTIFIER,
        INTEGER_LITERAL,
        DOUBLE_LITERAL,
        STRING_LITERAL,
        OPERATOR, 
        STRING_ESCAPE_SEQUENCE,
        POTENTIAL_DOUBLE,
        POTENTIAL_COMMENT,
        COMMENT,
    };

    static const char* sTokenTypeStrings[] = {  
        "WHITESPACE",  
        "IDENTIFIER",
        "INTEGER_LITERAL",
        "DOUBLE_LITERAL",
        "STRING_LITERAL",
        "OPERATOR", 
        "STRING_ESCAPE_SEQUENCE",
        "POTENTIAL_DOUBLE",
        "POTENTIAL_COMMENT",
        "COMMENT",   
    };

    class Token {
        public:
            enum TokenType mType{WHITESPACE};
            string mText;
            size_t mLineNumber{0};

            void debugPrint() const;
    };

    class tokenizer{
        public:
            vector<Token> parse(const string &inProgram);
        private:
            void endToken(Token &token, vector<Token> &tokens);
    };
}