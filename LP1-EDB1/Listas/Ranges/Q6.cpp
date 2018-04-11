#include <iostream>
#include <iterator>
 
int* compact(int *first, int *last) {
    /*Aloccating max possible size to my auxiliar pointer. */
    int *aux = new int[std::distance(first,last)];
    int count=0;
    for(auto i=0; i < std::distance(first,last); ++i) {

        //Checking positive values.
        if(*(first+i) > 0) {
            *(aux+count) = *(first+i);
            count++;
        }
    }

    //Compacting.
    while(count > 0) {
        *first = *aux;
        first++;
        aux++;
        count--;
    }

    return first;
}
 
int main() {
    int A[] = {-2, -8, 2, 7, -3, 10, 1, 0, -3, 7};

    //Printing original array.
    std::cout << ">>> Array BEFORE compact: " << std::endl;
    std::cout << "[ ";
    for(auto& e : A) {
        std::cout << e << " ";
    }
    std::cout << "]" << std::endl;
 
    //Apply function
    auto result = compact(std::begin(A), std::end(A));

    //Printing compacted array.
    std::cout << ">>> Array AFTER compact: " << std::endl;
    std::cout << "[ ";
    for(auto i(0); i < std::distance(std::begin(A), result); ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << "]" << std::endl;
 
    std::cout << std::distance(std::begin(A), result) << std::endl;
 
    return 0;
}