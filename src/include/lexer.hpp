#pragma once
#include <string>
#include <vector> 
#include "syntaxToken.hpp"

class Lexer {

private:
	int _position = 0;
	char Current();
	std::string text;

public:
	Lexer(std::string _text);
	SyntaxToken NextToken();	
};
