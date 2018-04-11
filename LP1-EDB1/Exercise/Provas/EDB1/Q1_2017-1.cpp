#include <iostream>
#include <cmath>
 
int poww(int a, int b) {
    int k;
    if(b == 1) {
        return a;
    }
    else if(b == 0) {
        return 1;
    }
    if(b % 2 == 0) {
        k = poww(a, b/2);
        return k * k;
    }
    k = poww(a, (b-1)/2);
    return k * k * a;
}
 
int main() {
    int x = 2;
    int y = 12;
    //std::cout << "A potencia vale: " << poww(5,7) << ", e deveria valer: " << pow(5,7) << "\n";
    std::cout << ">>> A potencia de " << x << " elevado a " << y << " vale: " << poww(x,y) << "\n";
    std::cout << ">>> Deveria valer: " << pow(x,y) << "\n"; 
    return 0;
}