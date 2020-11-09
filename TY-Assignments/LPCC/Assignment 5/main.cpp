#include "expcon.h"

int main (int argc, char* argv[]) {

	std::string input_expression( argv[1] );
	std::cout << "\n" << input_expression << "\n\n";

	// store the operands
	std::vector<char> OPERANDS;
	for (int i=0; i<input_expression.length(); i++) {
		if ( (input_expression[i] >= 'a' && input_expression[i] <= 'z')
			|| (input_expression[i] >= 'A' && input_expression[i] <= 'Z') ) {
			OPERANDS.push_back( input_expression[i] );
		}	
	}

	// 'var=' this part of input expression is excluded
	// then converted to prefix expression for further processing
	std::string infix = input_expression.substr(2, input_expression.length());
	std::string prefix = infixToPrefix( infix, OPERANDS );

	std::map<char, std::string> threeAddressCode = generateThreeAddressCode( prefix, OPERANDS );
	printThreeAddressCodeTable( threeAddressCode );

	std::cout << OPERANDS.front() << "=" << OPERANDS.back() << "\n";
	
	return 0;
}