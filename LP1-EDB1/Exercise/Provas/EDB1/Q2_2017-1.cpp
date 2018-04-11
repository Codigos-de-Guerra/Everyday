#include <iostream>

int count = 0;

int search(int *first, int *last) {
    int *everfirst = first;
    while(first != last) {
        int imid = (last - first)/2;
        int *pos = first+imid;
        if(*pos < *(pos+1) && *pos < *(pos-1)) {
            count += 2;
            return pos-everfirst;
        }
        else if(*pos < *first) {
            count += 3;
            last = pos;
        }
        else if(*pos > *first) {
            count += 4;
            first = pos;
        }
        else {
            count += 4;
        }
    }
    return last-first;
}
 
int main() {
    //int A[] = {0,1,2,3,4,5,-1};
    //int A[] = {1,2,3,4,5,-1,0};
    //int A[] = {2,3,4,5,-1,0,1};
    //int A[] = {3,4,5,-1,0,1,2};
    //int A[] = {4,5,-1,0,1,2,3};
    //int A[] = {5,-1,0,1,2,3,4};
    int A[] = {76,78,85,92,93,100,23,37,42,51,58,64,67,69,73};

    std::cout << ">>> Array size: " << std::distance(std::begin(A), std::end(A)) << "\n";
    std::cout << ">>> Array: [ ";
    for(auto& e : A) {
        std::cout << e << " ";
    }
    std::cout << "]\n";
    auto r = search(std::begin(A), std::end(A));
    std::cout << ">>> Ordenado ciclicamente no indice " << r << ", com valor " << A[r] << "\n";
    std::cout << "Iteracoes realizadas: " << count << "\n";
    return 0;
}
 