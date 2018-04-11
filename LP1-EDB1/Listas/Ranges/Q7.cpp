#include <iostream>
#include <iterator>
 
int* copy(int *first, int *last, int *d_first) {
    while(first != last) {
        *d_first = *first;      //Copies value.
 
        //Goes to next position on both arrays.
        first++;
        d_first++;
    }
    return d_first++;
}
 
int main () {
    int A[] = {1, 2, 3, 4, 5};// Vetor "fonte".
    int B[] = {0, 0, 0}; //Vetor "destino".
 
    // Copiar elementos 2, 3, e 4 para o inicio de B.
    auto b_last = copy(std::begin(A)+1 , std::begin(A)+4, std::begin(B));
   
    // O comando abaixo deveria imprimir B com o conteudo 2,3,4.
    std::cout << ">>> Copied Array: " << std::endl;
    std::cout << "[ ";
    for(auto i(std::begin(B)); i != b_last; ++i) {
        std::cout << *i << " ";
    }
    std::cout << "]" << std::endl;
 
    return 0;
}