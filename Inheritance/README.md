# Inheritance


## What is inheritance ?

In C++, inheritance is a mechanism that allows a derived class to inherit properties and behaviors from a base class. The derived class can then add new properties and behaviors, or override the ones inherited from the base class. This allows developers to create new classes based on existing ones, without having to write all of the code from scratch.

In C++, there are three types of inheritance:

* **Public Inheritance:** In public inheritance, the public and protected members of the base class become public and protected members of the derived class, respectively. The private members of the base class are not accessible by the derived class. Public inheritance is the most common type of inheritance.

* **Protected Inheritance:** In protected inheritance, the public and protected members of the base class become protected members of the derived class. The private members of the base class are not accessible by the derived class.

* **Private Inheritance:** In private inheritance, the public and protected members of the base class become private members of the derived class. The private members of the base class are not accessible by the derived class. Private inheritance is the least common type of inheritance.

To create a derived class in C++, we use the syntax:

```cpp
class DerivedClassName : accessSpecifier BaseClassName {
    // ...
};
```

Here, `DerivedClassName` is the name of the derived class, `accessSpecifier` is either public, protected, or private to specify the type of inheritance, and `BaseClassName` is the name of the *base class*.

For example, let's say we have a base class Animal with two public methods: `eat()` and `sleep()`. We want to create a derived class `Dog` that inherits from `Animal` and adds a new public method `bark()`. Here's how we would define the `Dog` class:

```cpp
class Dog : public Animal {
  public:
    void bark() {
      cout << "The dog is barking." << endl;
    }
};
```

Here, we use public inheritance to indicate that the public methods of `Animal` should be public in `Dog`. We then define a new public method `bark()` in `Dog`.

To create an object of the `Dog` class, we would use the syntax:

```cpp
Dog myDog;
```

Now, we can call the `eat()`,` sleep()`, and `bark()` methods on the `myDog` object:


```cpp
myDog.eat(); // Output: "The animal is eating."
myDog.sleep(); // Output: "The animal is sleeping."
myDog.bark(); // Output: "The dog is barking."
```

Here, the `eat()` and `sleep()` methods are inherited from the `Animal` class, and the `bark()` method is defined in the Dog class.


```cpp
#include<iostream>

using namespace std;

class Animal {
public:
    void eat() {
        cout << "The animal is eating." << endl;
    }
    void sleep() {
        cout << "The animal is sleeping." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "The dog is barking." << endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        cout << "The cat is meowing." << endl;
    }
    
    // Overriding 
    void eat() { 
        cout << "nam nam nam" << endl;
    }
};

int main() {

    Dog myDog;
    myDog.eat(); // Output: "The animal is eating."
    myDog.sleep(); // Output: "The animal is sleeping."
    myDog.bark(); // Output: "The dog is barking."

    Cat cat;

    cat.eat(); // method is overwritten
    
}
```






---

## Behind the scenes


Inheritance in C++ is implemented using a mechanism called class subtyping. When a derived class is created, the compiler generates a new class that has all of the properties and methods of the base class, as well as any additional properties and methods defined in the derived class. The derived class is said to be a subtype of the base class, meaning that it can be treated as if it were an instance of the base class.

When a member function is called on an object of a derived class, the compiler first checks to see if the function is defined in the derived class. If it is, the derived class version of the function is called. If it is not, the compiler looks for the function in the base class. If the function is found in the base class, the base class version of the function is called.

If a derived class defines a member function with the same name and signature as a member function in the base class, the derived class function overrides the base class function. This is called function overriding. When a member function is overridden in a derived class, the base class version of the function is hidden, and only the derived class version is visible to the compiler.

In C++, inheritance can be used to implement a number of powerful programming techniques, including polymorphism, which allows objects of different classes to be treated as if they were of the same type, and virtual functions, which allow functions to be dynamically bound at runtime based on the type of the object being operated on.

When a C++ program with inheritance is compiled, the compiler generates assembly code that defines each class and its methods. For each derived class, the compiler generates code that includes the layout and structure of the base class, followed by any additional properties and methods defined in the derived class.

When a member function is called on an object of a derived class, the compiler generates assembly code that first checks whether the function is defined in the derived class. If it is, the compiler generates a direct call to the function in the derived class. If the function is not defined in the derived class, the compiler generates code that looks up the function in the vtable of the object's class hierarchy. The vtable is a table of function pointers that maps each virtual function in the class hierarchy to its implementation in the appropriate derived class.

When a function is overridden in a derived class, the compiler generates assembly code that replaces the function pointer in the vtable for that function with a pointer to the implementation in the derived class. When a virtual function is called on an object of a derived class, the compiler generates assembly code that looks up the function pointer in the vtable for the object's class hierarchy and jumps to the implementation of the function specified by the pointer.

Overall, the implementation details of C++ inheritance and virtual functions can be complex and vary between different compilers and architectures. However, at a high level, C++ inheritance involves generating code that includes the layout and structure of the base class, as well as any additional properties and methods defined in the derived class, and using a vtable to dynamically bind virtual function calls to their appropriate implementations in the class hierarchy.


```
; Define the base class Animal
Animal:
    ; Define the vtable for Animal
    dd Animal__vtable

    ; Define the properties of Animal
    dd Animal__name
    dd Animal__sound

    ; Define the methods of Animal
    Animal__speak:
        mov eax, Animal__sound
        ret

    ; Define the name of Animal
    Animal__name:
        db "Animal", 0

; Define the derived class Dog
Dog:
    ; Define the vtable for Dog
    dd Dog__vtable

    ; Define the properties of Dog
    dd Animal__name
    dd Dog__sound
    dd Dog__breed

    ; Define the methods of Dog
    Dog__speak:
        mov eax, Dog__sound
        ret

    ; Define the name of Dog
    Dog__name:
        db "Dog", 0

    ; Define the breed of Dog
    Dog__breed:
        db "Golden Retriever", 0

; Define the vtable for Animal
Animal__vtable:
    dd Animal__speak

; Define the vtable for Dog
Dog__vtable:
    dd Dog__speak

; Create an instance of Dog
section .data
myDog: 
    dd Dog__vtable
    dd Dog__name
    dd Dog__sound
    dd Dog__breed

; Call the speak() method on myDog
section .text
global main
main:
    mov eax, [myDog]
    mov ebx, [eax]
    call [ebx]
```
