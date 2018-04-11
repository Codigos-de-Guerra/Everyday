#include <iostream>

int digitSum(int n) {
	if(n % 10 == n) {
		return n;
	}
	return digitSum(n/10) + n%10;
}

int main(int argc, char const **argv) {
	char *end;
	int x = strtol(argv[1], &end, 10);
	if(*end != '\0') {
		std::cerr << "Invalid number " << argv[1] << ".\n";
		return -1;
	}

	std::cout << "DigitSum returns " << digitSum(x) << "\n";

	return 0;
}