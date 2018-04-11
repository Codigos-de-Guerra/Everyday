#include <iostream>

long int cannonball(int altura) {
	if(altura == 1) {
		return 1;
	}
	return cannonball(altura-1) + altura*altura;
}

int main(int argc, char const **argv) {
	char *end;
	int height = strtol(argv[1], &end, 10);
	if(*end != '\0') {
		std::cerr << "Invalid number " << argv[1] << ".\n";
		return -1;
	}

	auto total = cannonball(height);
	std::cout << "There can be stacked " << total << " cannonballs.\n";

	return 0;
}