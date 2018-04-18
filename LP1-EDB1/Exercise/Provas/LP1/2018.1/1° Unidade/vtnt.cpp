#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

int Gasoline(std::vector<int> &alturas) {
	int gas = 0;
	int aux = 0;
	int min_aux = 0;
	int min_aux2 = 0;
	int minor = 0;
	int minor2 = 0;
	
	for(auto it = alturas.begin(); it != alturas.end(); it++) {
		aux = *it - *(it+1);
		min_aux += aux;
		min_aux = fmin(min_aux, 0);
		if(minor > min_aux) {
			minor = min_aux;
		}
	}
	
	for(auto it = alturas.end() - 1; it >= alturas.begin(); it--) {
		aux = *it - *(it-1);
		min_aux2 += aux;
		min_aux2 = fmin(min_aux2, 0);
		if(minor2 > min_aux2) {
			minor2 = min_aux2;
		}
	}
	
	gas = fmin(minor, minor2);
	
	return std::abs (gas);
}


int main(int argc, char const **argv) {
	if(argc != 2) {
		std::cerr << "Command line input is not enough\n";
		return -1;
	}
	std::istringstream filestream(argv[1]);	// Command line argument as string.
	std::string filename;			//String to receive input.
	filestream >> filename;
	
	std::ifstream ifs;
	ifs.open(filename.c_str());	//Opens reading file.
	
	std::string line;	//Variable to help me know the amount of lines
	std::vector<int> heights;

	std::ofstream ofs;
	ofs.open("saida.txt");

	
	while(ifs.good()) {
		std::getline(ifs, line);
		int num;
		std::stringstream ss(line);
		while( !ss.eof() ) {
			ss >> num;
			heights.push_back(num);
		}
		
		if( heights.size() != 1) {
			int result = Gasoline(heights);
			std::cout << result << "\n";
			ofs << result << "\n";
		}
		else {
			std::cout << 0 << "\n";
			ofs << 0 << "\n";
		}

		heights.erase( heights.begin(), heights.end() );
	}
	
	ifs.close();
	ofs.close();

	return 0;
}
