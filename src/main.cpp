#include <iostream> 
#include "include/lexer.hpp" 

// SyntaxTree has a Root which is a Node 
// each node is an expression either binary or number

// we may need to remodel so that there are children in every node
// those children will also be Expressions

// For each node we can print numberExpression and opToken 
// and call recursive function on right child of BE again

class SyntaxExpression{

};

class NumberExpressionSyntax : public SyntaxExpression{
public:    
    SyntaxToken number_token;
    NumberExpressionSyntax(SyntaxToken NumberToken){
        number_token = NumberToken;
    }
};

class BinaryExpressionSyntax : public SyntaxExpression{
public:
    SyntaxExpression left,right;
    SyntaxToken operatorToken;
    BinaryExpressionSyntax(SyntaxExpression _left, SyntaxToken _operatorToken, SyntaxExpression _right) {
        left = _left;
        operatorToken = _operatorToken;
        right = _right;
    }
};

class SyntaxNode : public SyntaxExpression{
    
};

class SyntaxTree {
public:    
    SyntaxNode Root;
    SyntaxTree(SyntaxNode root){
        Root = root;
    }
};



class Parser{

public:
    std::vector <SyntaxToken> _tokens;
    int _position;

    Parser(std::string text){
        std::vector <SyntaxToken> tokens;
        Lexer lex(text);
        SyntaxToken token;

        while (token.kind != SyntaxTokenKind::FileEndToken) {
            token = lex.NextToken();
            if (token.kind != SyntaxTokenKind::WhiteSpaceToken){
                tokens.push_back(token);
            }                
        }
        _tokens = tokens;

        // check for tokens given by lexer
        // for (int i = 0; i < _tokens.size(); i++)
		// std::cout << "[" << _tokens[i].kind << "," << _tokens[i].position << "," << _tokens[i].value << "]\n";
    }

    SyntaxToken Peek(int offset) {
        int index = _position + offset;
        if (index >= _tokens.size()) return _tokens.back();
        return _tokens[index];
    }
    
    SyntaxToken Current() {return Peek(0);}

    SyntaxToken NextToken() {
        SyntaxToken current = Current();
        _position++;
        return current;
    }

    SyntaxToken Match(SyntaxTokenKind kind){
        if(Current().kind == kind){
            return NextToken();
        }
        return *new SyntaxToken(kind,"",_position);
    }

    SyntaxExpression ParsePrimaryExpression() {
        SyntaxToken numberToken = Match(SyntaxTokenKind::NumberToken);
        return *new NumberExpressionSyntax(numberToken);
    }

    SyntaxNode Parse(){
        SyntaxExpression left = ParsePrimaryExpression();

        while(Current().kind == SyntaxTokenKind::PlusToken ||
              Current().kind == SyntaxTokenKind::MinusToken)
        {
            SyntaxToken operatorToken = NextToken();
            SyntaxExpression right = ParsePrimaryExpression();
            left = *new BinaryExpressionSyntax(left,operatorToken,right);
        }

        // convert left from SyntaxExpression to SyntaxNode
        // and the return left
        SyntaxNode *ConvertingExpressionToNode = (SyntaxNode *)&left;
        return *ConvertingExpressionToNode;
    }
    
};


int main() {
	// Way to call lexer on a the peice of code called strTest

	std::string strTest = "69 + 69 * 18 - 18 / 2 * 123";

    Parser p1(strTest);

    SyntaxTree t1(p1.Parse());

    // make this function
    // Print_somehow(SyntaxNode t1.root())

}