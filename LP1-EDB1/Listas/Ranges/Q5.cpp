#include <iostream>
#include <iterator>
 
int dot_product(const int *a_first, const int *a_last, const int *b_first) {
    int ans = 0;
    while(a_first != a_last) {
        ans += (*a_first) * (*b_first);
 
        /*Increments both vectores positions to check*/
        a_first++;
        b_first++;
    }
    return ans;
}
 
int main () {
    // Desejamos multiplicar a=[1 , 3 , -5] · b=[4 , -2 , -1].
 
    // Both vectors stored on the same array.
    int Vet [] = {1 , 3 , -5 , 4 , -2 , -1 };
 
    //Apply function.
    auto result = dot_product(std::begin(Vet), std::begin(Vet)+3, std::begin(Vet)+3);
   
    // O comando abaixo deveria imprimir 3 , se correto .
    std::cout << " >>> O resultado eh: " << result << std::endl;
            //[1 ,3 , -5]·[4 , -2 , -1] = (1)(4)+(3)( -2)+( -5)( -1)
            //= 4 - 6 + 5
            //= 3.
    
    return 0;
}