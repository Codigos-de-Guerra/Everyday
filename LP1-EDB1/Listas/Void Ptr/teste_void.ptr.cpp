#include <iostream>
#include <cstring>
#include <iterator>

using byte = unsigned char;
using Compare = bool(const void*, const void*, size_t);
/*
	NOT NECESSARY
bool comp(const void *a, const void *b, size_t size) {
	byte *aa = static_cast<byte*> (const_cast<void*> (a));
	byte *bb = static_cast<byte*> (const_cast<void*> (b));

	return *aa < *bb;
}
*/	

void selection_sort(const void *first, const void *last, size_t size) {
	byte *f = static_cast<byte*> (const_cast<void*> (first));
	byte *l = static_cast<byte*> (const_cast<void*> (last));
	byte *min = new byte[size];

//	std::cout << (float) *f << "\n";	

	while(f <= (l-size)) {
		//First value is already considerated the lowest.
		min = f;
		for(auto i(f+size); i < l; i += size) {
			//Checks if the object we are looking is lower than the considerated to be the lowest
			if(std::memcmp(i, min, size) < 0) {
				//Changes 'min' to new found lowest
				//std::memcpy(min, i, size); //memcpy is for values, but i am using it for the pointer reference. Therefore [min = i].
				min = i;
			}
		}
		//Swaps values if it is lowest.

		/*Creates a temporaly pointer to save some of my reusable data*/
		byte *temp = new byte[size];

		std::memcpy(temp, f, size);
		std::memcpy(f, min, size);
		std::memcpy(min, temp, size);

		/*Desallocates its memory space*/
		delete [] temp;
		
		//Increments sorted part.
		f += size;
	}
}
  
	

int main() {

/*OK*/
	int I[] = {8,2,3,6,0,5,1,9,4,7};

/*NOT OKAY ;-;*/
	double D[] = {1.22, 1.3, 1.5, 1.1, 1.4, 1.7, 1.2, 1.8, 2.1, 1.6, 1.0};
/*OK!*/
	char C[] = {'g','h','i','f','a','b','j','c','d','e'};
/*NOT OKAY ;-;*/
	std::string S[] = {"um","sete","cinco","nove","tres"};

	
/* Not a important part 
	auto size_A = sizeof(A)/sizeof(A[3]); //Getting type size
	std::cout << size_A << "\n";	
*/

	//Printing Original Array
	std::cout << ">>> Original Int Array:\n [ ";
	for(auto& e : I) {
		std::cout << e << " ";
	}
	std::cout << "]\n";

	selection_sort(std::begin(I), std::end(I), sizeof(I[0]));


	//Printing "sorted" Array
	std::cout << ">>> Sorted Int Array:\n [ ";
	for(auto& i : I) {
		std::cout << i << " ";
	}
	std::cout << "]\n\n\n";

	//Printing Original Array
	std::cout << ">>> Original Double Array:\n [ ";
	for(auto& e : D) {
		std::cout << e << " ";
	}
	std::cout << "]\n";

	selection_sort(std::begin(D), std::end(D), sizeof(D[0]));


	//Printing "sorted" Array
	std::cout << ">>> Sorted Double Array:\n [ ";
	for(auto& i : D) {
		std::cout << i << " ";
	}
	std::cout << "]\n\n\n";

	//Printing Original Array
	std::cout << ">>> Original Char Array:\n [ ";
	for(auto& e : C) {
		std::cout << e << " ";
	}
	std::cout << "]\n";

	selection_sort(std::begin(C), std::end(C), sizeof(C[0]));


	//Printing "sorted" Array
	std::cout << ">>> Sorted Char Array:\n [ ";
	for(auto& i : C) {
		std::cout << i << " ";
	}
	std::cout << "]\n\n\n";

	//Printing Original Array
	std::cout << ">>> Original String Array:\n [ ";
	for(auto& e : S) {
		std::cout << e << " ";
	}
	std::cout << "]\n";

	selection_sort(std::begin(S), std::end(S), sizeof(S[0]));


	//Printing "sorted" Array
	std::cout << ">>> Sorted String Array:\n [ ";
	for(auto& i : S) {
		std::cout << i << " ";
	}
	std::cout << "]\n\n\n";

	return 0;
}	

