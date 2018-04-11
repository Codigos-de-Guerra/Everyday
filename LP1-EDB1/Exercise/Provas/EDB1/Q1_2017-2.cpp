#include <iostream>
#include <algorithm>

int equal_indc(int *first, int *last) {
	int *everfirst = first;
	while(first < last) {
		auto pos = std::distance(first, last)/2;
		auto m = first+pos;
		if(*m == m-everfirst) {
			return m-everfirst;
		}
		else if(*m > m-everfirst) {
			last = m;
		}
		else {
			first = m+1;
		}
	}
	return -1;
}


int main() {
	int A[] = {-12, -8, 2, 17 , 28, 34, 35, 46, 57, 61};
	int index = equal_indc(std::begin(A), std::end(A));
	if(index != -1) {
		std::cout << ">>> A[" << index << "] = " << A[index] << "\n";
	}
	else {
		std::cout << ">>> Nao existe um indice 'i' tal que A[i] == i.\n";
	}
	return 0;
}