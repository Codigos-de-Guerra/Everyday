#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>
int count = 0;
int counti = 0;

/*-------------------DO NOT USE. TO MANY COMPARISONS.----------------------*/
std::pair<int, int> min_max(int *first, int *last) {
    int menor = *first;
    int maior = *first;
    for(int i=1; i<(last-first); ++i) {
        if(*(first+i) > maior) {
            count++;
            maior = *(first+i);
        }
        else if(menor > *(first+i)) {
            count += 2;
            menor = *(first+i);
        }
        else {
            count += 2;
        }
    }
    std::pair <int, int> foo;
    foo = std::make_pair(menor, maior);
    return foo;
}
/*------------------------------USE THIS ONE-------------------------------*/
std::pair<int, int> min_max2(int *first, int *last) {
    if((last-first) == 1) {
        counti++;
        auto p = std::make_pair(*first, *first);
        return p;
    }
    counti++;
    std::pair <int, int> foo = std::minmax(*first, *(first+1));
    for(int i=2; i<(last-first); i+=2) {
        if(foo.first > std::min(*(first+i), *(first+i+1))) {
            counti++;
            foo.first = std::min(*(first+i), *(first+i+1));
        }
        else if(foo.second < std::max(*(first+i), *(first+i+1))) {
            counti += 2;
            foo.second = std::max(*(first+i), *(first+i+1));
        }
        else {
            counti += 2;
        }
    }
    if((last-first) % 2 == 0) {
        counti++;
        foo.first = std::min(foo.first, *(first+(std::distance(first,last) - 1)));
        foo.second = std::max(foo.second, *(first+(std::distance(first,last) - 1)));
    }
    else {
        counti++;
    }
    return foo;
}
 
int main() {
    //int A[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    //int A[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int A[] = {23,53,10,7567,87890,2,34,893,452,34,54,68231,-12,4,56,91294,34,7,9,3,-44,100000};
    auto result = min_max(std::begin(A), std::end(A));
    auto r = min_max2(std::begin(A), std::end(A));

    std::cout << ">>> Menor valor = " << result.first << "\n>>> Maior valor = " << result.second << "\n";
    std::cout << ">>> Comparacoes executadas: " << count << "\n";
    std::cout << ">>> Tamanho do vetor: " << std::end(A)-std::begin(A) << "\n\n";
 
    std::cout << ">>> Menor valor = " << r.first << "\n>>> Maior valor = " << r.second << "\n";
    std::cout << ">>> Comparacoes executadas: " << counti << "\n";
    std::cout << ">>> Tamanho do vetor: " << std::end(A)-std::begin(A) << "\n";

    return 0;
}