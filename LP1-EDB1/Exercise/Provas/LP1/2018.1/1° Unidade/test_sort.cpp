#include <iostream>
#include <cstring>

using byte = unsigned char;
using Compare = int(const void*, const void*);

void sort_bubble_2(const void *first, const void *last, size_t size, Compare *cmp) {
	
	byte *f = (byte*) first;
	byte *l = (byte*) last;
	
	bool is_sorted = false;

	while(!is_sorted) {
		is_sorted = true;
		for(auto i(l-size); i >= f; i -= size) {
			if(cmp(i-size, i) == 1) {
				byte *temp = new byte [size];
		
				std::memcpy(temp, i-size, size);
				std::memcpy(i-size, i, size);
				std::memcpy(i, temp, size);
	
				delete [] temp;
				is_sorted = false;
			}
		}
		for(auto j(f+size); j < l; j += size) {
			if(cmp(j, j+size) == 1) {
				byte *temp = new byte [size];
				
				std::memcpy(temp, j, size);
				std::memcpy(j, j+size, size);
				std::memcpy(j+size, temp, size);
				
				delete [] temp;
				is_sorted = false;
			}
		}
	}
}

int cmp(const void *a, const void *b) {
	int *aa = (int*) (a);
	int *bb = (int*) (b);

	if(*aa < *bb) {
		return -1;
	}
	else if(*aa == *bb) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	int A[] = {3,6,1,8,23,61,20,15,83,41};
	
	sort_bubble_2(std::begin(A), std::end(A), sizeof(A[0]), cmp);
	
	std::cout << ">>> Sorted Array:\n [ ";
	for(auto& e : A) {
		std::cout << e << "  ";
	}
	std::cout << "]\n";

	return 0;
}
