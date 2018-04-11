#include <iostream>
#include <iterator>
 
int* min(int *first, int *last) {
    int* min = first;   //On the first iteraction the minimun is itself.
    first++;                    //Start checking from the 2nd element.
    while(first != last) {
        if(*first < *min) {     //Updating minimun value.
            min = first;
        }
        first++;
    }
    return min;
}
int main() {
    int A[] = {1,2,-3,-4,5,-6};
 
    //Deveria imprimir -6.
    auto result = min(std::begin(A), std::end(A));
    std::cout << ">>> Minimun value: " << *result << " found at " << std::distance(std::begin(A),result) << std::endl;
 
    //Deveria imprimir -4.
    result = min(std::begin(A)+1, std::begin(A)+5);
    std::cout << ">>> Minimun value: " << *result << " found at " << std::distance(std::begin(A)+1,result) << std::endl;
 
    return 0;
}