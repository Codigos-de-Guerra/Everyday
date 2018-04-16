#include <iostream>
#include <cstring>
#include <iterator>

using byte = unsigned char;

void reverse(void *first, void *last, size_t size) {
	byte *f = (byte*) first;
	byte *l = (byte*) last;
	
	std::cout << size << "\n";
//	std::cout << (std::string) *f << "\n";

	auto j(l-size);
	for(auto i(f); i < j; i += size) {
		byte *temp = new byte[size];
		std::memcpy(temp, i, size);
//		std::cout << (int) *temp << "\n";
		std::memcpy(i, j, size);
		std::memcpy(j, temp, size);
		j -= size;
		delete[] temp;
	}
}

void * lsearch( const void *first, const void *last, const void value, size_t size ) {
	byte *f = (byte*) first;
	byte *l = (byte*) last;
	byte v = (byte) value;
//	memcpy(v, value, size);

	//auto tam = std::distance(f, l)/size; Needed for another search

	while(f < l) {
		if(memcmp(f, v, size) == 0) {
			return f;
		}
		f += size;
	}

	return last;
}	


int main() {
//	int A[] = {2,3,4,5,6,10,1};
	char A[] = {'r', 't', 'a', 'q', 'l'};
//	double A[] = { 1.5, 3.75, 2.25, 9.62};
//	std::string A[] = {"um", "dois", "tres", "quatro", "cinco"};
	std::cout << ">>> Before reverse:\n[ ";
	for(auto& e : A) {
		std::cout << e << "  ";
	}
	std::cout << "]\n";

	reverse(std::begin(A), std::end(A), sizeof(A[0]));

	std::cout << ">>> After reverse:\n[ ";
	for(auto& e : A) {
		std::cout << e << "  ";
	}
	std::cout << "]\n";
/*-----------------------------------------------------------*/
	auto result =(int *) clone(std::begin(A)+1, std::begin(A)+4, sizeof(A[0]));
	
	std::cout << ">>> Cloned Array:\n[ ";
	std::cout << *result << "\n";

	return 0;
}
	
