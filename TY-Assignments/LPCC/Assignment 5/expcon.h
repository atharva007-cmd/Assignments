#pragma once

#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <regex>
#include <algorithm>

const std::vector<char> OPERATORS = { '+', '-', '*', '/', '^' };

// geneate 3-address code
std::map<char, std::string> generateThreeAddressCode ( std::string, std::vector<char>& );

// display three-address-code
void printThreeAddressCodeTable ( const std::map<char, std::string>& );

// convert infix expression to prefix expression
std::string infixToPrefix ( std::string, std::vector<char>& );

// get new operand
char getNewOperand ( int&, std::vector<char>& );

// get precedence of operator
int getPrecedence ( char );