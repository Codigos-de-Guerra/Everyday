#include <iostream>
#include <iterator>
#include <vector>

int* unique(int *first, int *last) {

    //Aloccating max possible size for my auxiliar pointer.
    int *aux = new int[std::distance(first, last)+1];
    int k=0;                //Some auxiliar int.

    for(int i=0; i<std::distance(first, last); ++i) {
        //Boolean to consider int to be not unique.
        bool NOTunik = false;

        for(int j=0; j<i && NOTunik == false; j++) {
            if(*(first+i) == *(first+j)) {
                NOTunik = true;
            }
        }
        /* If it is not a NOTunik, then it is unique.*/
        if (!NOTunik) {
            *(aux+k) = *(first+i);          //Saving unique values.
            k++;
        }
    }
    /*Passing them to my original array*/
    for(int i=0; i<k; ++i) {
        *(first+i) = *(aux+i);
    }

    return first+k;
}
 
int main () {
    int A[] = {1, 2, 1, 2, 3, 3, 1, 2, 4, 5, 3, 4, 5};

    //Printing original array.
    std::cout << ">>> Array BEFORE unique: " << std::endl;
    std::cout << "[ ";
    for(auto& e : A) {
        std::cout << e << " ";
    }
    std::cout << "]" << std::endl;
 
    // Aplicar unique sobre A
    auto last = unique(std::begin(A), std::end(A));
    // O comando abaixo deveria imprimir A com o conteudo 1, 2, 3, 4, 5.

    //Printing negated array.
    std::cout << ">>> Array AFTER unique: " << std::endl;
    std::cout << "[ ";
    for(auto i(std::begin(A)); i != last; ++i) {
        std::cout << *i << " ";
    }
    std::cout << "]" << std::endl;

    // Mostra o novo tamanho de A , que seria 5.
    std::cout << " >>> O comprimento (logico) de A apos unique () eh: "
                << std::distance (std::begin(A) , last) << std::endl;

    return 0;
}