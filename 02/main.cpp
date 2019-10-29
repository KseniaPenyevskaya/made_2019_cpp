#include <iostream>
#include <stdexcept>

class Allocator
{
public:
	Allocator(size_t maxSize);
	~Allocator();
	char* alloc(size_t size);
	//void reset();
	void free();
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
		throw std::logic_error("Out of memory");
	}
}

void Allocator::free() {
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

			try {
				Allocator a(static_cast<size_t>(inputSizeBuf));
				a.free();
				char* ptr = a.alloc(static_cast<size_t>(inputAllocSize));
			}
			catch (std::exception & e) {
				std::cerr << e.what();
				return 2;
			}
			//std::cout << std::hex << ptr;

		}
		else {
			std::cerr << "Wrong size";
		}
	}
	else {
		std::cerr << "Wrong args";
	}
}
