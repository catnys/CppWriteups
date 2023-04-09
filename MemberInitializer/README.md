# Member Initializer

## What is member initializer ?
In object-oriented programming, a member initializer is a special syntax used to initialize the members of a class or struct in its constructor. It allows you to set the initial values of the member variables of an object as soon as it is created.

A member initializer consists of a colon followed by a list of member-initializer pairs enclosed in parentheses, where each member-initializer pair consists of a member name followed by an expression in braces or parentheses that initializes the member.

For example, consider the following class with a member initializer:


```cpp
class MyClass {
public:
  MyClass(int a, int b) : x(a), y(b) {}
private:
  int x;
  int y;
};
```

In this example, the constructor of the MyClass takes two integer parameters a and b, and uses a member initializer to initialize the private data members x and y of the class with these values. This way, the data members are initialized before the body of the constructor is executed, ensuring that the object is properly initialized before any other code can use it.

Using member initializers can also improve performance by avoiding unnecessary default construction and assignment of class members.

## Further example 

```cpp
class Rectangle {
public:
  Rectangle(int w, int h) : width(w), height(h) {}
  int area() const { return width * height; }
private:
  int width;
  int height;
};
```

In this example, the Rectangle class has a constructor that takes two integer parameters w and h, and uses a member initializer to initialize the private data members **`width`** and **`height`** with these values.

The **`area()`** function is a member function that calculates the area of the rectangle by multiplying its **`width`** and **`height`**, and returns the result. Since the **`width`** and **`height`** members are initialized in the constructor, we can be sure that the area function will always return the correct result.

To create an instance of the Rectangle class and compute its area, we can write:


```cpp
Rectangle r(4, 5);
int a = r.area(); // a is 20
```

In this example, we create an instance of the Rectangle class with a width of 4 and a height of 5, and then call the **`area()`** function to compute its area. The result is stored in the variable a, which is equal to 20.
