#include <iostream>
#include "calculator.h"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Wrong args";
		return 1;
	}

	char* input = argv[1];

	try {
		std::cout << eval(input)<<std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what();
		return 2;
	}
	return 0;
}
