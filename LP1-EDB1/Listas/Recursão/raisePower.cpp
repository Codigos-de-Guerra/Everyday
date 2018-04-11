#include <iostream>

int raiseToPower(int n, int k) {
	if(k == 0) {
		return 1;
	}
	return raiseToPower(n, k-1)*n;
}

int main(int argc, char const **argv) {
	char *end;
	int n = strtol(argv[1], &end, 10);
	if(*end != '\0') {
		std::cerr << "Invalid number " << argv[1] << ".\n";
		return -1;
	}

	int k = strtol(argv[2], &end, 10);
	if(*end != '\0') {
		std::cerr << "Invalid number " << argv[2] << ".\n";
		return -2;
	}
	int pou = raiseToPower(n, k); 

	std::cout << n << " powered by " << k << " = " << pou << "\n";

	return 0;
}