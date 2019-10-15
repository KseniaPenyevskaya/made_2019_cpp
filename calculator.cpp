#include <cstring>
#include <stdexcept>
#include "calculator.h"

struct Res {
	int result_value;
	const char* next_token;
};

//this expression parser based on recursive descent method

// check if symbol is '-' or number
Res get_number(const char* s) {
	// add '-'
	int signum = 1;
	if (*s == '-') {
		signum = -1;
		++s;
	}
	if (!(*s >= '0' && *s <= '9')) {
		throw std::logic_error("Wrong expression");
	}

	int number = 0;
	while (*s >= '0' && *s <= '9') {
		// multidigit number
		number *= 10;
		number += *s - '0';
		++s;
	}
	return {signum*number, s};
}

// 
Res mult_div(const char* s) {
	Res result;
	Res left = get_number(s);
	int l_val = left.result_value;
	s = left.next_token;

	while ((*s == '*') || (*s == '/')) {
		Res right = get_number(s + 1);
		int r_val = right.result_value;

		if (*s == '*') {
			l_val = l_val * r_val;
		}
		if (*s == '/') {
			l_val = l_val / r_val;
		}
		s = right.next_token;
	}
	result.result_value = l_val;
	result.next_token = s;
	return result;
}

Res add_sub(const char* s) {
	Res result;
	Res left = mult_div(s++);
	int l_val = left.result_value;
	s = left.next_token;
	while ((*s == '+') || (*s == '-')) {
		Res right = mult_div(s + 1);
		int r_val = right.result_value;
		if (*s == '+') {
			l_val = l_val + r_val;
		}
		if (*s == '-') {
			l_val = l_val - r_val;
		}
		s = right.next_token;
	}
	result.result_value = l_val;
	result.next_token = s;
	return result;
}

int eval(const char* expression)
{
	size_t size = strlen(expression);
	const char* s = expression;

	int result = 0;
	while (s < expression + size) {
		Res res = add_sub(s);
		result = res.result_value;
		s = res.next_token;
	}

	return result;
} 
