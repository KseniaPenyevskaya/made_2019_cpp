#include <cstring>
#include <cctype>
#include "parser.h"

void GetToken(char* text, void(*tokenFound)(), void(*TokenNumber)(Token tokNumb),
	void(*TokenString)(Token tokStr)) {
	size_t size = strlen(text);
	char* s = text;
	
	while(s < text+size){
		Token newToken;
		newToken.type = number;
		newToken.str = "";
		//check if symbol is separator
		while (!(std::isspace(*s)) && (*s != '\0')) {
			newToken.str.push_back(*s);
			newToken.type = ((*s >= '0' && *s <= '9') && (newToken.type == number)) ? number : string; // determine type of Token
			s++;
			}
		
		if (newToken.str!="") {
			tokenFound();
		}
		// choosing callback function based on Token's type
		switch (newToken.type) {
		case number:
			TokenNumber(newToken);
			break;
		case string:
			TokenString(newToken);
			break;
			}
		s++;
	}
}

void ParseText(char* text, void(*Start)(), void(*Finish)(), void(*TokenFound)(),void(*TokenNumber)(Token tokNumb),
	void(*TokenString)(Token tokStr)) {
	Start();
	GetToken(text, *TokenFound, *TokenNumber, *TokenString);
	Finish();
}
