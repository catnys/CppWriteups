## Lvalue and Rvalue in C++

In C++, "lvalue" and "rvalue" are terms used to categorize expressions based on whether they can appear on the left-hand side (lvalue) or the right-hand side (rvalue) of an assignment. These terms are essential in understanding how C++ handles values and expressions, especially in the context of assignments and function calls.

### Lvalue (Left Value)

- An lvalue represents an object or a memory location that has a name. You can think of an lvalue as something you can assign a value to.
- Lvalues can be variables, array elements, or references.
- Examples of lvalues:
  - Variables: `int x = 42;`, where `x` is an lvalue.
  - Array elements: `int arr[5]; arr[2] = 10;`, where `arr[2]` is an lvalue.
  - References: `int& ref = x;`, where `ref` is an lvalue.

### Rvalue (Right Value)

- An rvalue represents a temporary or a value that can only appear on the right side of an assignment. It's a value, not necessarily associated with a memory location or object name.
- Rvalues are typically used as the source of data in expressions and cannot be assigned to.
- Examples of rvalues:
  - Constants and literals: `int result = 5 + 3;`, where `5 + 3` is an rvalue.
  - Temporary values: The result of a function call that returns by value is often an rvalue.
  - Expressions: `int sum = x + y;`, where `x + y` is an rvalue.

The distinction between lvalues and rvalues is important for understanding how C++ handles assignment, function overloading, and move semantics. For example, in C++11 and later, rvalue references (`&&`) are used for efficient move semantics, allowing you to move resources from one object to another, often improving performance when working with temporary values.

Here's a simple example demonstrating lvalues and rvalues:

```cpp
int a = 5;      // 'a' is an lvalue
int b = 2;      // 'b' is an lvalue
int c = a + b;  // 'a + b' is an rvalue
