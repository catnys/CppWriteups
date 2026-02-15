#include<iostream>

int main() {
    // Accessing the static variable defined in static.cpp
    extern int s_variable; // Declare the variable to use it here
    std::cout << "Value of static variable: " << s_variable << std::endl;

    return 0;
}