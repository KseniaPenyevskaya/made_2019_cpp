run: calc
calc: main.o calculator.o
	g++ main.o calculator.o -o calc

main.o calculator.o: calculator.h

clean: 
	rm -rf  *.o calc
test: test_number test_mult test_un_minus test_expr test_wrong_expr
test_number:
	./calc "5"
test_mult:
	./calc "2*3"
test_un_minus: 
	./calc "5--5"
test_expr:
	./calc "7*4-10+7/7"
test_wrong_expr: 
	./calc "3*h"
