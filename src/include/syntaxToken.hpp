#pragma once
#include <string>
#include <vector> 
#include "syntaxTokenKind.hpp"

class SyntaxToken {
public:	
	SyntaxTokenKind kind;
	std::string value;
	int position;
	SyntaxToken();
	SyntaxToken(SyntaxTokenKind _kind, std::string _value, int _position);

};