<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
</head>
<body>
  <h1>Static and Extern Keywords in C++</h1>

  <h2>Table of contents</h2>
  <ul>
    <li><a href="#static-variable">Static variable</a></li>
    <li><a href="#static-function">Static function</a></li>
    <li><a href="#static-class-member">Static class member</a></li>
    <li><a href="#extern-variable">Extern variable</a></li>
      <li><a href="Further-example">Further example</a></li>
  </ul>



  <h2>Summary</h2>
  <p>The keywords "static" and "extern" in C++ are used to control the visibility and linkage of variables and functions. "Static" is used to create variables, functions, and class members with internal linkage, meaning they are only accessible within the same translation unit (source file). "Extern" is used to declare variables and functions with external linkage, meaning they can be accessed from other translation units.</p>

  <h2 id="static-variable">Static variable</h2>
  <p>When the keyword "static" is used in the context of a variable inside a function or method, it means that the variable has static storage duration. A static variable retains its value between function or method calls, and its lifetime is the entire duration of the program. Additionally, static variables have internal linkage, meaning they can only be accessed within the same translation unit.</p>

  <pre>
    void myFunction() {
       static int count = 0; // static variable
       count++;
       cout << "Count: " << count << endl;
    }
  </pre>

  <h2 id="static-function">Static function</h2>
  <p>When the keyword "static" is used in the context of a function or method, it means that the function or method has internal linkage. An internal linkage means that the function or method can only be called from within the same translation unit (source file).</p>

  <pre>
    static void myStaticFunction() {
       // do something
    }
  </pre>

  <h2 id="static-class-member">Static class member</h2>
  <p>When the keyword "static" is used in the context of a class member, it means that the member belongs to the class itself, rather than to any instance of the class. A static class member is shared by all instances of the class.</p>

  <pre>
    class MyClass {
       public:
          static int myStaticVariable; // static class member
    };
    int MyClass::myStaticVariable = 0; // definition of static class member
  </pre>

  <h2 id="extern-variable">Extern variable</h2>
  <p>The keyword "extern" is used to declare a variable that has external linkage. An external linkage means that the variable can be accessed from other translation units (source files). The declaration of an extern variable does not define the variable, but rather indicates to the compiler that the variable is defined elsewhere.</p>

  <p>Here is an example of an extern variable declared in one source file and defined in another:</p>

  <pre>
    // file1.cpp
    extern int myExternVariable;

    // file2.cpp
    int myExternVariable = 42;
  </pre>

<h2 id="Further-example">Further example</h2>
    
    
```cpp
    // example.cpp
#include <iostream>

// Declare a static variable 'count' within the namespace of this file.
static int count = 0;

// Declare an extern variable 'globalCount' which is defined in another file.
extern int globalCount;

void foo() {
    count++;
    globalCount++;
}

int main() {
    std::cout << "count: " << count << std::endl; // Prints 0
    std::cout << "globalCount: " << globalCount << std::endl; // Undefined behavior
    foo();
    std::cout << "count: " << count << std::endl; // Prints 1
    std::cout << "globalCount: " << globalCount << std::endl; // Depends on the value in the other file
    return 0;
}
```
    
```cpp
    // globals.cpp
int globalCount = 0;
```

In this example, we declare a static variable count inside the source file. This means that the variable can only be accessed from within this source file, and any changes made to it will not be visible outside of the file.

We also declare an extern variable globalCount, which is defined in another source file. This allows us to use the variable in this file, but it must be defined elsewhere.

The foo() function increments both the count and globalCount variables. When we call foo() in main(), we can see that the count variable is incremented correctly, but the value of globalCount is undefined because it is defined in another file.

