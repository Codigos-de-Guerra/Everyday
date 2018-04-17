#include <iostream>
#include <utility>

using UnaryPredicate = bool (const int *);

bool pred(const int *a) {
	//Predicado para considerar apenas inteiros ímpares
	return *a % 2 == 1;
}

std::pair<int *, int *> array_selected(const int *first, const int *last, UnaryPredicate *p) {
	int count = 0; //Auxiliary var for size.
	
	int *a_first = const_cast<int*> (first);
	int *a_last = const_cast<int*> (last);

	for(auto i(first); i != last; i++) {
		if(p(i)) {
			a_first = (int*) i;
			break;
		}
	}

	for(auto i(first); i != last; i++) {
		if(p(i)) {
			count++;
		}
	}
	a_last = (int*) last-count;

	int *a = new int [count];

	for(auto i(first); i != last; i++) {
		if(p(i)) {
			*a = *i;
			a++;
		}
	}

	return std::make_pair(a_first, a_last);
}


int main() {
	int A[] = {6,1,3,5,8,2,4};
	std::cout << ">>> Original Array:\n[ ";
	for(auto& e : A) {
		std::cout << e << " ";
	}
	std::cout << "]\n";
	auto result = array_selected(std::begin(A), std::end(A), pred);

	for(auto i(result.first); i < result.second; i++) {
		std::cout << *i << "  ";
	}

	return 0;
}


	
