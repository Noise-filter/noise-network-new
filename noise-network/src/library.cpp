#include "library.h"

#include <iostream>

int main() {
    hello();
    return 0;
}

void hello() {
    std::cout << "Hello, World!" << std::endl;
    int *a;
}

int add(int x, int y) { return x + y; }