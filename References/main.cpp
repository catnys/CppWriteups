#include <iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10;
    int y = 20;

    // 1. Basic Reference Declaration
    // 'ref' is an alias for 'x'. They share the same memory address.
    int& ref = x; 

    ref = 50; // Modifying 'ref' actually modifies 'x'
    std::cout << "x is now: " << x << "\n"; // Output: 50

    // 2. References cannot be reseated
    // This line does NOT make 'ref' point to 'y'.
    // Instead, it copies the VALUE of 'y' into 'x' (the target of 'ref').
    ref = y; 
    std::cout << "x is now: " << x << "\n"; // Output: 20

    // 3. Pass-by-Reference Example
    // Calling swap with references avoids pointers (*a) and address-of operators (&x)
    std::cout << "Before Swap: x=" << x << ", y=" << y << "\n";
    swap(x, y);
    std::cout << "After Swap:  x=" << x << ", y=" << y << "\n";

    return 0;
}