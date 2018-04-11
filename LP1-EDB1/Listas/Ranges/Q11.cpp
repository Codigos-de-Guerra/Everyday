#include <iostream> // std :: cout , std :: endl
#include <iterator> // std :: begin () , std :: end ()

void rotate(int *first, int *n_first, int *last) {
    int *aux = new int[std::distance(first, n_first)+1];
    int j=0;
    for(int i(0); i<std::distance(first, n_first); ++i) {
        *(aux+j) = *(first+i);
        j++;
    }
    j=0;
    for(int i(0); i<std::distance(first, last); ++i) {
        if(i < std::distance(n_first, last)) {
            *(first+i) = *(n_first+i);
        }
        else {
            *(first+i) = *(aux+j);
            j++;
        }
    }
}

int main () {
    int A[] = {1, 2, 3, 4, 5, 6, 7};

    //Printing original array.
    std::cout << ">>> Array BEFORE rotate: " << std::endl;
    std::cout << "[ ";
    for(auto& e : A) {
        std::cout << e << " ";
    }
    std::cout << "]" << std::endl << std::endl;
    // Aplicar rotate, de maneira que 3 passe a ser o novo "primeiro" elemento em A.
    rotate (std::begin(A), std::begin(A)+2, std::end(A));
    // O comando abaixo deveria imprimir A com o conteúdo 3, 4, 5, 6, 7, 1, 2.

    //Printing rotated array.
    std::cout << ">>> Array AFTER rotate: " << std::endl;
    std::cout << "[ ";
    for(auto i(std::begin(A)); i != std::end(A); ++i) {
        std::cout << *i << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}