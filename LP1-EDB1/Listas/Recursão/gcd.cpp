#include <iostream>

int gcd(int x, int y) {
	if(x == y*(x/y)) {
		return y;
	}
	int rest = x % y;
	return gcd(y, rest);
}

int main(int argc, char const **argv) {
	char *end;
	int x = strtol(argv[1], &end, 10);
	if(*end != '\0') {
		std::cerr << "Invalid number " << argv[1] << ".\n";
		return -1;
	}

	int y = strtol(argv[2], &end, 10);
	if(*end != '\0') {
		std::cerr << "Invalid number " << argv[2] << ".\n";
		return -2;
	}
	int great = gcd(x,y);
	std::cout << "GCD of " << x << " and " << y << " is " << great << "\n";

	return 0;
}	