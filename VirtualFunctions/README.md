# Virtual Functions

In C++, virtual functions allow polymorphic behavior, which means that a function can be dynamically bound at runtime depending on the type of object on which it is called.

When a function is declared as virtual in a base class, any derived class that overrides that function can choose to use its own implementation of the function or call the implementation in the base class using the **`BaseClass::function()`** syntax. This allows the behavior of a function to vary depending on the runtime type of the object.

For example, consider a base class Animal and two derived classes Cat and Dog. If Animal has a virtual function called **`speak()`**, both **`Cat`** and **`Dog`** can override this function with their own implementation. Then, if you have a pointer to an **`Animal`** object, you can call the **`speak()`** function on it, and the appropriate implementation will be called based on the actual type of the object (i.e., **`Cat::speak()`** or **`Dog::speak()`**). This can be useful for creating flexible and extensible code that can work with a variety of related objects.

When a virtual function is called through a pointer or reference to an object, the actual function called is determined dynamically, at runtime, based on the type of the object pointed to or referred to. This is known as dynamic dispatch or late binding. The process of selecting the appropriate function to call is handled by the compiler using a virtual function table or virtual method table.

Each class that has virtual functions has its own vtable, which contains pointers to the virtual functions defined for that class. The vtable is usually implemented as an array of function pointers, where each element corresponds to a virtual function in the class. When a class is derived from a base class, the derived class will have its own vtable that contains pointers to its own virtual functions as well as any inherited virtual functions.

```cpp
class Animal {
public:
    virtual void speak() const {
        std::cout << "Animal speaks!\n";
    }
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Dog barks!\n";
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "Cat meows!\n";
    }
};
```

In the example above, the **`speak()`** function is declared as virtual in the Animal class. Both Dog and Cat override this function with their own implementation using the override keyword. When **`speak()`** is called on an Animal object, the appropriate implementation will be called based on the actual type of the object.


# Further Topics

1. **Virtual destructors**: When a class has virtual functions, it's important to have a virtual destructor as well. This allows the destructor of the most derived class to be called when deleting an object through a base class pointer. If the destructor is not virtual, only the base class destructor will be called, leading to memory leaks and undefined behavior. For example:


```cpp
class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {
public:
    ~Derived() override {}
};
```

2. **Virtual inheritance:** When a class is derived from two or more base classes that have a common base class, virtual inheritance is used to prevent the creation of duplicate base class objects. In this case, the most derived class must initialize the virtual base class explicitly in its constructor. For example:


```cpp
class Animal {
public:
    virtual void speak() const = 0;
};

class Mammal : virtual public Animal {
public:
    virtual void breathe() const {}
};

class Bird : virtual public Animal {
public:
    virtual void fly() const {}
};

class Bat : public Mammal, public Bird {
public:
    Bat() : Animal(), Mammal(), Bird() {}
    void speak() const override {}
};
```



3. **Pure virtual functions:** A pure virtual function is a virtual function that has no implementation in the base class and must be overridden in derived classes. This is useful when you want to define a base class interface that must be implemented by derived classes, but the implementation is specific to each derived class. A pure virtual function is declared using the **`= 0`** syntax, like this:

```cpp
class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

class Circle : public Shape {
public:
    double area() const override { return pi * radius * radius; }
    double perimeter() const override { return 2 * pi * radius; }
private:
    double radius;
    static constexpr double pi = 3.141592653589793;
};
```


In this example, Shape is an abstract base class that defines the interface for shapes. Circle is a concrete derived class that implements the `area()` and `perimeter()` functions for circles. Since Shape has pure virtual functions, it cannot be instantiated directly, but only through derived classes that implement the pure virtual functions.
