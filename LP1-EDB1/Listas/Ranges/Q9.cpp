#include <iostream>
#include <iterator>
#include <vector>
#include <cassert>
 
//std::cout, std::endl
//std :: begin () , std :: end ()
 
enum ball_t {B=0, W=1}; // Black and White .
int *sort_marbles (int *first , int *last ) {
    int ans = 0;
    auto size = std::distance(first, last);
    for(auto i(0); i<size; ++i) {
        ans += *(first+i);
    }
    for(auto i(size-1);i>=0; --i) {
        while(ans > 0) {
            *(first+i) = 1;
            ans--;
            last--;
            i--;
        }
        *(first+i) = 0;
    }
    return last;
}
 
int main () {
    int A[] = {W, B, B, W, W, B, W}; // input
    auto size_A = sizeof(A)/sizeof(ball_t);
    int A_sorted[] = {B, B, B, W, W, W, W};//expected output

    //Printing original array.
    std::cout << ">>> Array BEFORE sort_marbles: " << std::endl;
    std::cout << "[ ";
    for(auto& e : A) {
        std::cout << e << " ";
    }
    std::cout << "]" << std::endl;
 
    auto result = sort_marbles(std::begin(A), std::end(A));
    // White marbles shoud start at position 3 whithin the array.

    assert(std::distance(std::begin(A), result) == 3);
    // Validate answer

    //Printing new array.
    std::cout << ">>> Array AFTER sort_marbles: " << std::endl;
    std::cout << "[ ";
    for(auto i(0u); i < size_A; ++i) {
        std::cout << A[i] << " ";
        assert(A[i] == A_sorted[i]);
    }
    std::cout << "]" << std::endl;

    return 0;
}