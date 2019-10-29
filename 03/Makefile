run: mylib parse

mylib: createlib rlib

createlib: parser.o
	ar rc libparser.a parser.o
rlib:
	ranlib libparser.a

main.o:
	g++ -c main.cpp
parser.o:
	g++ -c parser.cpp

parse: main.o
	g++ main.o -L. -lparser -o parse 

test:
	./parse "67 word 7df f90 4"
clean:
	rm -rf *.o parse
