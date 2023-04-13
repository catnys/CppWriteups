# Pointers

In C++, you can initialize dynamic arrays in several ways. Here are some examples:

Using the new operator:

```cpp
int size = 10;
int* arr = new int[size];.
```
This creates an integer array of size 10 on the heap and assigns its address to the pointer variable arr.

Using a default constructor:

```cpp
std::vector<int> vec(10);
int* arr = vec.data();
```

The code above creates a dynamic array using the std::vector class, which is a convenient way to manage dynamic arrays in C++. The data() method returns a pointer to the underlying array.

Using an initializer list:

The code snippet bleow creates an integer array with the values 1, 2, 3, 4, and 5.

```cpp
int* arr = new int[]{1, 2, 3, 4, 5};
```

Hence we're allocating a dynamic memory on heap, so we must deallocate the memory when we're done with the array using the `delete[]` operator:

```cpp
delete[] arr;
```

## What if we don't know the size of the array ?

In that case we can use the new operator with a runtime variable to allocate memory dynamically. Here's an example:


```cpp
int size;
std::cout << "Enter the size of the array: ";
std::cin >> size;

int* arr = new int[size];
```

In this example, the user is prompted to enter the size of the array at runtime, and the new operator is used to allocate memory dynamically based on the value entered by the user.

Note that when we allocate memory dynamically, we must deallocate it using the delete[] operator when we've done with the array, like above:


```cpp
delete[] arr;
```

Failure to do so can result in memory leaks, where the memory remains allocated even after the program has finished executing, potentially leading to reduced system performance and instability.





## Further example

This C++ code defines a function printArray that takes a pointer to an integer array and the size of the array as arguments. The function then prints the values of the array elements using three different methods:

1. Using pointer arithmetic **`(*(ptrArray + i))`**
2. Using pointer arithmetic with addition **`(*ptrArray + i)`**
3. Using array indexing **`(ptrArray[i])`**


The main function of the code defines an integer array array with some values, and then dynamically allocates an integer array myArray using the new operator. It also defines some integer variables a, ptr, ptrb, ptrc and assigns them some values. It then prints the values of these variables and their memory addresses using the cout statement.

Finally, the main function calls the printArray function with the array array and its size as arguments, and the function prints the values of the array elements using the three methods mentioned earlier.

Overall, this code demonstrates how to access the elements of an integer array using pointers and array indexing, and how to print the values of the array elements using different methods.

```cpp
#include<iostream>

using namespace std;

void printArray(int *ptrArray, int size) {
	int i;
	for (i = 0; i < size; i++) {
		cout << "*(ptrArray + "<< i  <<") = " << * (ptrArray + i) << endl;
	}

	cout << "-----" << endl;

	for (i = 0; i < size; i++) {
		cout << "*ptrArray + " << i << " = " << *ptrArray + i << endl;
	}

	cout << "-----" << endl;

	for (i = 0; i < size; i++) {
		cout << "ptrArray[" << i << "]= " << ptrArray[i] << endl;
	}
}

int main() {

	int array[] = { 1,2,3,4,5 };
	int* myArray;
	myArray = new int[5];

	int a;
	int* ptr;
	int* ptrb;
	int* ptrc;

	a = 900;
	ptr = &a;

	ptrb = array;
	
	cout << "a : " << a << endl;
	cout << "*ptr : " << *ptr << endl;
	cout << "ptr : " << ptr << endl;
	cout << "&a : " << &a << endl;

	cout << "-----" << endl;

	cout << "array : " << array << endl;
	cout << "&array[0] : " << &array[0] << endl;
	cout << "&array : " << &array << endl;
	cout << "ptrb : " << ptrb << endl;
	cout << "*ptrb : " << *ptrb << endl;
	cout << "array[0] : " << array[0] << endl;
	
	cout << "-----" << endl;
	int size = sizeof(array) / sizeof(int);

	printArray(array, size);

}
```
