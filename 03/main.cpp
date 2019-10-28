#include <iostream>
#include "parser.h"

void callbackStart() {
	std::cout << "Start" << std::endl;
}
void callbackFinish() {
	std::cout << "Finish" << std::endl;
}

void TokenFound() {
	std::cout << "Token found ";
}

void TokenNumber(Token tok) {
	std::cout << "cbTokenNumber: " << tok.str << std::endl;
}

void TokenString(Token tok) {
	std::cout << "cbTokenString: " << tok.str << std::endl;
}


int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Wrong args";
		return 1;
	}
	char* input = argv[1];

	ParseText(input, &callbackStart , &callbackFinish, &TokenFound, &TokenNumber, &TokenString);
	return 0;
}
