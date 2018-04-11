#include <iostream>
#include <iterator>
#include <algorithm>
 
void reverse(int *first, int *last) {
    while(first < last-1) {
        std::swap(*first, *(last-1));   //Swapping vector elements.
        first++;
        last--;
    }
}
 
int main() {
    int A[] = {1,2,3,4,5};
    std::cout << ">>> Array BEFORE reverse: " << std::endl;
    std::cout << "[ ";
    for(auto& e : A) {
        std::cout << e << " ";
    }
    std::cout << "]" << std::endl;
 
    //Aplicar reverse sobre todo o vetor.
    reverse(std::begin(A), std::end(A));
 
    //O comando abaixo deveria imprimir A com o conteúdo 5,4,3,2,1.
    std::cout << ">>> Array AFTER first reverse: " << std::endl;
    std::cout << "[ ";
    for(auto& e : A) {
        std::cout << e << " ";
    }
    std::cout << "]" << std::endl;
 
    //Aplciar reverse sobre parte do vetor.
    reverse(std::begin(A)+1, std::begin(A)+4);
 
    //O comando abaixo deveria imprimir A com o conteúdo 5,2,3,4,1.
    std::cout << ">>> Array AFTER second reverse: " << std::endl;
    std::cout << "[ ";
    for(auto& e : A) {
        std::cout << e << " ";
    }
    std::cout << "]" << std::endl;
 
    return 0;
}