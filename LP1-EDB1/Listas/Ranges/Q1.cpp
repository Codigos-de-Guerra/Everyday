#include <iostream>
#include <iterator>
 
void negate(int *first, int *last) {
    while(first != last) {
        *first = (-1)*(*first);
        first++;    //Going through vector.
    }
}
int main() {
    int Vet[] = {1,2,-3,-4,5,-6,7};
 
    //Printing original array.
    std::cout << ">>> Array BEFORE negate: " << std::endl;
    std::cout << "[ ";
    for(auto& e : Vet) {
        std::cout << e << " ";
    }
    std::cout << "]" << std::endl;
 
    //Function to negate.
    negate(std::begin(Vet), std::end(Vet));
 
    //Printing negated array.
    std::cout << ">>> Array AFTER negate: " << std::endl;
    std::cout << "[ ";
    for(auto& e : Vet) {
        std::cout << e << " ";
    }
    std::cout << "]" << std::endl;
 
    return 0;
}
