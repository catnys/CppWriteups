#include <stdio.h>

int main() {

    int *myptr = nullptr; // Initialize pointer to null

    myptr = new int; // Dynamically allocate memory
    *myptr = 42; // Assign value to allocated memory

    printf("Value: %d\n", *myptr);

    delete myptr; // Free allocated memory
    return 0;
}