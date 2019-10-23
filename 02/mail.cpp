#include <iostream>

class Allocator
{
public:
	Allocator(size_t maxSize);
	~Allocator();
	char* alloc(size_t size);
	void reset();
private:
	char* ptrBuff;
	size_t sizeBuff;
	size_t offset;
};
Allocator::Allocator(size_t maxSize){
	offset = 0;
	sizeBuff = maxSize;
	ptrBuff = (char*)malloc(sizeBuff);
}
Allocator::~Allocator() {
	std::free(ptrBuff);
}

char* Allocator::alloc(size_t size) {
	size_t newOffset = offset + size;

	if (0 == sizeBuff) {
		return nullptr;
	}
	if (0 == size) {
		return nullptr;
	}
	if (newOffset <= sizeBuff) {
		char* ptr = ptrBuff + offset;
		offset = newOffset;
		std::cout << std::hex << ptr;
		return ptr;
	} else if(newOffset > sizeBuff) {
		std::cout << "Out of memory";
		return 0;
	}
}

void Allocator::reset() {
	offset = 0;
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		std::cerr << "Wrong args";
		return 1;
	}
	int inputSizeBuf = atoi(argv[1]);
	int inputAllocSize = atoi(argv[2]);

	if (inputSizeBuf) {
		if (inputSizeBuf > 0) {
			Allocator a(static_cast<size_t>(inputSizeBuf));
			a.reset();
			char* ptr = a.alloc(static_cast<size_t>(inputAllocSize));
			//std::cout << std::hex << ptr;

		}
		else {
			std::cerr << "Wrong size";
		}
	}
	else {
		std::cerr << "Wrong args";
