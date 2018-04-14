#include <iostream>
#include <cstring>
#include <iterator>

using byte = unsigned char;
using Compare = bool(const void*, const void*, size_t);

bool comp(const void *a, const void *b, size_t size) {
	byte *aa = static_cast<byte*> (const_cast<void*> (a));
	byte *bb = static_cast<byte*> (const_cast<void*> (b));

	return *aa < *bb;
}
	

void selection_sort(const void *first, const void *last, size_t size, Compare comp) {
	byte *f = static_cast<byte*> (const_cast<void*> (first));
	byte *l = static_cast<byte*> (const_cast<void*> (last));
	byte *min;

	//std::cout << (float) *f << "\n";	

	while(f <= (l-size)) {
		//First value is already considerated the lowest.
		min = f;
		for(auto i(f+size); i < l; i += size) {
			//Checks if the object we are looking is lower than the considerated to be the lowest
			if(comp(i, min, size)) {
				//Changes 'min' to new found lowest
				min = i;
			}
		}
		//Swaps values if it is lowest.
		std::swap(*f, *min);
		//Increments sorted part.
		f += size;
	}
}  
	

int main() {

/*Buçanha sai certo*/
	int A[] = {8,2,3,6,0,5,1,9,4,7};
/*Buçanha bugada*/
	float A[] = {1.22, 1.3, 1.5, 1.1, 1.4, 1.7, 1.2, 1.8, 1.6, 1.0};
/*Buçanha sai certo*/
	char A[] = {'g','h','i','f','a','b','j','c','d','e'};
/*Buçanha bugada*/
	std::string A[] = {"um","tres","cinco","sete","nove"};

	byte *algo = (byte*) std::begin(A);
	//std::cout << (float) *(algo) << "\n";

	auto size_A = sizeof(A)/sizeof(A[3]); //Getting type size
	std::cout << size_A << "\n";	


	//Printing Original Array
	std::cout << ">>> Original Array:\n [ ";
	for(auto& e : A) {
		std::cout << e << " ";
	}
	std::cout << "]\n";
	std::cout << sizeof(A[2]) << "\n";

	selection_sort(std::begin(A), std::end(A), sizeof(A[0]), comp);


	//Printing "sorted" Array
	std::cout << ">>> Sorted Array:\n [ ";
	for(auto& i : A) {
		std::cout << i << " ";
	}
	std::cout << "]\n";

	return 0;
}	

