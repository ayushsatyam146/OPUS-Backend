
#include <string>
#include <vector> 
#include "../include/syntaxToken.hpp"


SyntaxToken::SyntaxToken() {
	kind = SyntaxTokenKind::NullToken;
	value = "";
	position = 0;
}

SyntaxToken::SyntaxToken(SyntaxTokenKind _kind, std::string _value, int _position) {
	kind = _kind;
	value = _value;
	position = _position;
}