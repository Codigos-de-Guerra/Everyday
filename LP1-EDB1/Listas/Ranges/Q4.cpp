#include <iostream>
#include <iterator> //std::begin(), std::end()
 
void scalar_multiplication(int *first, int *last, int scalar) {
    while(first != last) {
        *first = *first * scalar;
        first++;
    }
}
 
int main () {
    int Vet[] = {1 , 2 , -3 , -4 , 5 , -6};
    std::cout << ">>> Array BEFORE scalar_multiplication: " << std::endl;
    std::cout << "[ ";
    for(auto& e : Vet) {
        std::cout << e << " ";
    }
    std::cout << "]" << std::endl;
 
    //Apply function.
    scalar_multiplication(std::begin(Vet), std::end(Vet), 3);
    // O vetor resultante seria :
    // { 3 , 6 , -9 , -12 , 15 , -18 }.
 
    std::cout << ">>> Array AFTER scalar_multiplication: " << std::endl;
    std::cout << "[ ";
    for(auto& e : Vet) {
        std::cout << e << " ";
    }
    std::cout << "]" << std::endl;
 
    return 0;
}