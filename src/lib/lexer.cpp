#pragma once
#include <string>
#include <vector> 
#include "../include/lexer.hpp"


Lexer::Lexer(std::string _text) {
	text = _text;
}

char Lexer::Current() {
	if (_position >= text.size()) return '\0';
	return text[_position];
}

SyntaxToken Lexer::NextToken() {

	if (isdigit(Current())) {
		int start = _position;
		while (isdigit(Current())) _position++;
		std::string numeric_value = text.substr(start, _position - start);
		return *new SyntaxToken(SyntaxTokenKind::NumberToken, numeric_value, start);
	}

	if (Current() == ' ') {
		int start = _position;
		while (Current() == ' ') _position++;
		std::string space_value = text.substr(start, _position);
		return *new SyntaxToken(SyntaxTokenKind::WhiteSpaceToken, space_value, start);
	}

	if (Current() == '+')
		return *new SyntaxToken(SyntaxTokenKind::PlusToken, "+", _position++);
	else if (Current() == '-')
		return *new SyntaxToken(SyntaxTokenKind::MinusToken, "-", _position++);
	else if (Current() == '*')
		return *new SyntaxToken(SyntaxTokenKind::MultiplyToken, "*", _position++);
	else if (Current() == '/')
		return *new SyntaxToken(SyntaxTokenKind::DivideToken, "/", _position++);
	else if (Current() == '(')
		return *new SyntaxToken(SyntaxTokenKind::OpenBracetoken, "(", _position++);
	else if (Current() == ')')
		return *new SyntaxToken(SyntaxTokenKind::CloseBraceToken, ")", _position++);
	return *new SyntaxToken(SyntaxTokenKind::FileEndToken, "\0", _position++);
}

