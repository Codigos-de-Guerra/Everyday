#include <iostream>

int PasTriangulo(int n, int k) {
	if(n == k || k == 0) {
		return 1;
	} 
	return PasTriangulo(n-1, k-1) + PasTriangulo(n-1, k);
}

int main(int argc, char const **argv) {
	char *end;
	if(argc != 2) {
		std::cerr << "Wrong input entries. Try again.\n";
		return -1;
	}

	//Receives 'height' through command line and validates.
	int height = strtol(argv[1], &end, 10);
	if(*end != '\0') {
		std::cerr << "Invalid number " << argv[1] << ".\n";
		return -1;
	}
	for(int i=0; i<height; ++i) {
		//std::cout << i;
		for(int j=0; j<=i; ++j) {
			int Comb = PasTriangulo(i,j);
			std::cout << Comb << "  ";
		}
		std::cout << "\n";
	}

	return 0;
}