#include <iostream>

int digitalRoot(int n) {
	if(n % 10 == n) {
		return n;
	}
	return digitalRoot(n/10 + n%10);
}

int main(int argc, char const **argv) {
	char *end;
	int n = strtol(argv[1], &end, 10);
	if(*end != '\0') {
		std::cerr << "Invalid number " << argv[1] << ".\n";
		return -1;
	}
	int root = digitalRoot(n);
	std::cout << "DigitalRoot of " << n << " = " << root << "\n";

	return 0;
}