#include <iostream>
#include <iterator>

void partition(int *first, int *last, int *pivot) {

    /*Aloccating max possible sizes for my auxiliar pointers. */
    int *aux_me = new int[std::distance(first,last)];
    int *aux_eq = new int[std::distance(first,last)];
    int *aux_ma = new int[std::distance(first,last)];

    //Int to help me know the exactly amount of each part.
    int count_eq=0, count_me=0, count_ma=0;
    for(auto i(0); i<std::distance(first, last); ++i) {

        //Counts.
        if(*(first+i) > *pivot) {
            *(aux_ma+count_ma) = *(first+i);
            count_ma++;
        }
        else if(*(first+i) == *pivot) {
            *(aux_eq+count_eq) = *(first+i);
            count_eq++;
        }
        else {
            *(aux_me+count_me) = *(first+i);
            count_me++;
        }
    }

    //Prints.
    for(int i=0; i<std::distance(first,last); i++) {
        while(count_me > 0) {
            *(first+i) = *(aux_me);
            aux_me++;
            count_me--;
            i++;
        }
        while(count_eq > 0) {
            *(first+i) = *(aux_eq);
            aux_eq++;
            count_eq--;
            i++;
        }
        while(count_ma > 0) {
            *(first+i) = *(aux_ma);
            aux_ma++;
            count_ma--;
            i++;
        }
    }
}
int main() {
 
    int A[] = {-5, 7, 10, 7, 8, 9, 1, 7, -2, 3};
    std::cout << ">>> Array BEFORE partition: " << std::endl;
    std::cout << "[ ";
    for(auto& e : A) {
        std::cout << e << " ";
    }
    std::cout << "]" << std::endl << std::endl;
    partition(std::begin(A), std::end(A), std::begin(A)+3);
 
    std::cout << ">>> Array AFTER partition: " << std::endl;
    std::cout << "[ ";
    for(auto& e : A) {
        std::cout << e << " ";
    }
    std::cout << "]" << std::endl;
   
    return 0;
}