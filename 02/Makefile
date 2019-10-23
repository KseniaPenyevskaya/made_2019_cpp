test: c test_ok test_outOfMemory test_wrongArgs
c:
	g++ main.cpp -o alloc
test_ok:
	./alloc 300 3
test_outOfMemory:
	./alloc 30 300
test_wrongArgs:
	./alloc 30
