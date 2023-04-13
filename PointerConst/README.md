# Const With Pointers

In C++, both const int* ptr and int const* ptr declare a pointer to a constant integer. However, the difference lies in how they are interpreted by the compiler.

const int* ptr means that the integer being pointed to by ptr is constant and cannot be modified through the pointer. This means that the value of the integer can be modified using a different pointer or variable, but not through ptr.

int const* ptr, on the other hand, is equivalent to const int* ptr. It means that the integer being pointed to by ptr is constant and cannot be modified through the pointer. This is because the const keyword is applied to the int data type, making the integer constant.

In both cases, the pointer itself can be modified to point to a different integer, but any attempt to modify the value of the integer through the pointer will result in a compilation error.


```cpp
#include <iostream>

int main() {
    int x = 10;
    int y = 20;
    const int* ptr1 = &x;       // ptr1 points to a const int
    int const* ptr2 = &y;       // ptr2 points to a const int

    // The following assignments are not allowed since the pointed-to value is const
    // *ptr1 = 15;             
    // *ptr2 = 25;

    std::cout << "*ptr1: " << *ptr1 << std::endl;  // Output: *ptr1: 10
    std::cout << "*ptr2: " << *ptr2 << std::endl;  // Output: *ptr2: 20

    // The following assignments are allowed since the pointers themselves are not const
    ptr1 = &y;
    ptr2 = &x;

    std::cout << "*ptr1: " << *ptr1 << std::endl;  // Output: *ptr1: 20
    std::cout << "*ptr2: " << *ptr2 << std::endl;  // Output: *ptr2: 10

    return 0;
}
```


---


The other example;

```cpp
#include<iostream>
using namespace std;

void printArray(const int* ptr1, int const* ptr2) {
	for (; ptr1 != ptr2; ptr1++) {
		cout << "->" << *ptr1 << endl;
	}
}

int main() {
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	printArray(array + 2, array + 5);
	

}
```




---

Another case;

```cpp
int main() {
  char str[] = "Hello, world!";

  const char* ptr1 = str;     // ptr1 points to a const char
  // *ptr1 = 'h';            // Error: the value pointed to by ptr1 is const
  ptr1++;                     // OK: ptr1 can be modified to point to the next character

  char const* ptr2 = str;     // ptr2 points to a const char
  // *ptr2 = 'h';            // Error: the value pointed to by ptr2 is const
  ptr2++;                     // OK: ptr2 can be modified to point to the next character
}
```



