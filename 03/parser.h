#pragma once
#include <iostream>
#include <cstring>

enum typeToken { number, string };
struct Token {
	std::string str;
	typeToken type;
};

void ParseText(char* text, void(*Start)(), void(*Finish)(), void(*TokenFound)(), void(*TokenNumber)(Token tokNumb),
	void(*TokenString)(Token tokStr));
