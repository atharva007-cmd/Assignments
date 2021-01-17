#include "expcon.h"

// geneate 3-address code
std::map<char, std::string> generateThreeAddressCode ( std::string prefix, std::vector<char>& OPERANDS ) {

	std::map<char, std::string> threeAddressCodeTable;
	int asciiCharacter = 64;

	for (int i=prefix.length()-1; i>=0; i--) {
		
		// check if character is an OPERATOR
		if (std::find(OPERATORS.begin(), OPERATORS.end(), prefix[i]) != OPERATORS.end()) {
			
			// check if the following two characters are OPERANDS
			if ( std::find(OPERANDS.begin(), OPERANDS.end(), prefix[i+1]) != OPERANDS.end()
			&& std::find(OPERANDS.begin(), OPERANDS.end(), prefix[i+2]) != OPERANDS.end() ) {

				// prefix[i]: OPERATOR
				// prefix[i+1]: OPERAND-1
				// prefix[i+2]: OPERAND-2

				char newOperand = getNewOperand( asciiCharacter, OPERANDS );
				std::string newOperandString
							, newValue
							, oldValue;

				newOperandString.push_back(newOperand);
				newValue.push_back(prefix[i+1]); newValue.push_back(prefix[i]); newValue.push_back(prefix[i+2]);
				oldValue.push_back(prefix[i]); oldValue.push_back(prefix[i+1]); oldValue.push_back(prefix[i+2]);
				
				// storing new operand and it's respective value
				threeAddressCodeTable.emplace( newOperand, newValue );
				
				// replacing the prefix-substring with the new operand
				prefix.replace( prefix.find(oldValue), oldValue.length(), newOperandString );

				// reassigning the value for 'i' to reiterate over the new string
				i = prefix.length();
			}
		}
	}

	return threeAddressCodeTable;	
}

// display three-address-code
void printThreeAddressCodeTable ( const std::map<char, std::string>& table ) {
	// format: new-operand = old-operand-1 old-operator old-operand-2
	for ( auto& iterator: table ) { std::cout << iterator.first << "=" << iterator.second << "\n"; }
}

// convert infix expression to prefix expression
std::string infixToPrefix ( std::string infix, std::vector<char>& OPERANDS ) {

	std::string prefix;
	std::stack<char> stack;

	// reverse the infix-string
	std::reverse( infix.begin(), infix.end() );
	for (int i=0; i<infix.length(); i++) {
		// Interchange ')' and '('
		if ( infix[i] == ')') { infix[i] = '('; }
		else if ( infix[i] == '(') { infix[i] = ')'; }
	}

	for (int i=0; i<infix.length(); i++) {

		// Character is operand
		if (std::find(OPERANDS.begin(), OPERANDS.end(), infix[i]) != OPERANDS.end()) {
			prefix += infix[i];
		}
		// Character is '('
		else if (infix[i] == '(') {
			stack.push( infix[i] );
		}
		// Character is ')'
		else if (infix[i] == ')') {
			while ( (stack.top() != '(') && ( !stack.empty() ) ) {
				prefix += stack.top();
				stack.pop();
			}
			if ( stack.top() == '(' ) { stack.pop(); }			
		}
		// Character is operator
		else if (std::find(OPERATORS.begin(), OPERATORS.end(), infix[i]) != OPERATORS.end()) {

			// Stack empty, simply push operator on stack
			if ( stack.empty() ) { stack.push(infix[i]); }

			else {

				// precedence of infix[i] is greater than precedence of top of stack
				if( getPrecedence(infix[i]) > getPrecedence(stack.top()) ) {
					stack.push( infix[i] );
				}
				// precedence of infix[i] is equal to precedence of top of stack
				// and operator is '^'
				else if( getPrecedence(infix[i]) == getPrecedence(stack.top())
					&& infix[i] == '^' ) {
					while( getPrecedence(infix[i]) == getPrecedence(stack.top())
						&& infix[i] == '^' ) {
						prefix += stack.top();
						stack.pop();
					}
					stack.push( infix[i] );
				}
				// precedence of infix[i] is equal to precedence of top of stack
				else if( getPrecedence(infix[i]) == getPrecedence(stack.top()) ) {
					stack.push( infix[i] );
				}
				else {
					while( (!stack.empty())
						&& (getPrecedence(infix[i]) < getPrecedence(stack.top())) ) {
						prefix += stack.top();
						stack.pop();
					}
					stack.push( infix[i] );
				}
			}
		}
	}

	// push all the stack content to the prefix-string
	while ( !stack.empty() ) {
		prefix += stack.top();
		stack.pop();
	}
	
	// reverse the prefix-string
	std::reverse( prefix.begin(), prefix.end() );
	
	return prefix;
}

// get precedence of operator
int getPrecedence ( char m_operator ) {

	if( m_operator == '^' ) {
		return 3;	
	}
	else if ( m_operator == '*'
		|| m_operator == '/') {
		return 2;
	}
	else if ( m_operator == '+'
		|| m_operator == '-') {
		return 1;
	}
	else { return -1; }
}

// get new operand
char getNewOperand ( int& asciiValue, std::vector<char>& OPERANDS ) {

	// A-Z : 65-90
	// a-z : 97-122

	if (asciiValue == 90) { asciiValue = 96; }
	
	char operand = ++asciiValue;
	bool operandFound = false;
	
	while ( !operandFound ) {

		// if the operand already exists
		if ( std::find(OPERANDS.begin(), OPERANDS.end(), operand) != OPERANDS.end() ) {
			
			// try new one
			operand = ++asciiValue;
		} else {
			
			// new operand is found
			OPERANDS.push_back( operand );
			operandFound = true;
		}
	}

	return operand;
}