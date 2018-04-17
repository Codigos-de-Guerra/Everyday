#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

int Gasoline(std::vector<int> &alturas) {
	int gas = 0;
	int aux = 0;
	int min_aux = 0;
	for(auto it = alturas.begin(); it != alturas.end(); it++) {
		aux = *it - *(it+1);
		if(min_aux > fmin(aux, 0)) {
			min_aux = fmin(aux, 0);
		}
	}
}

void write(std::vector<int> &v) {
	std::cout << "[ ";
	for(auto it(v.begin()); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "]\n";
}


int main(int argc, char const **argv) {
	if(argc != 2) {
		cerr << "Command line input is not enough\n";
		return -1;
	}
	std::istringstream filestream(argv[1]);	// Command line argument as string.
	std::string filename;			//String to receive input.
	filestream >> filename;
	
	std::ifstream ifs;
	ifs.open(filename.c_str());	//Opens reading file.
	
	std::string line;	//Variable to help me know the amount of lines
	std::vector<int> heights;

	
	while(ifs.good()) {
		std::getline(ifs, line);
		int num;
		std::stringstream ss(line);
		while( !ss.eof() ) {
			ss >> num;
			heights.push_back(num);
		}
		if( heights.size() == 1) {
			std::cout << 0 << "\n";
		}
		else {
			
		write(heights);

		heights.erase( heights.begin(), heights.end() );
	}


}

