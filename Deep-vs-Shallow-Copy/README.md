# Deep Copy vs. Shallow Copy

In programming and data structures, "deep copy" and "shallow copy" refer to different approaches for copying data structures. These approaches determine the relationship between the original data and its copy, and how changes to one may affect the other. Here's a comparison of deep copy and shallow copy:

## Deep Copy

**Definition**: A deep copy is a copy operation that creates a completely independent duplicate of the original data and all of its nested elements.

**Characteristics**:
- It copies not only the top-level object but also all objects (and their contents) referenced or contained within the original data structure.
- Changes made to the deep copy do not affect the original, and vice versa. They are entirely independent.
- It involves recursive copying, ensuring that nested objects are also deeply copied.
- Deep copies are generally used when you want to maintain separate, distinct copies of data.

**Example**:

```cpp
#include <iostream>
#include <string>

class DeepCopyExample {
public:
    DeepCopyExample(const std::string& data) : data_(data) {}

    DeepCopyExample(const DeepCopyExample& other) : data_(other.data_) {}

    void printData() {
        std::cout << data_ << std::endl;
    }

private:
    std::string data_;
};

int main() {
    DeepCopyExample original("Original Data");
    DeepCopyExample deepCopy(original);

    original.printData(); // Output: Original Data
    deepCopy.printData(); // Output: Original Data

    // Modifying deepCopy doesn't affect original
    deepCopy.printData(); // Output: New Data
    original.printData(); // Output: Original Data

    return 0;
}
```

## Shallow Copy

**Definition**: A shallow copy is a copy operation that creates a new object, but it shares references to the same elements (objects or data) as the original.

**Characteristics**:
- It copies the top-level object and its references to other objects. However, it doesn't create duplicates of the referenced objects themselves.
- Changes made to the shallow copy may affect the original, and vice versa, especially if modifications are made to the shared objects.
- Shallow copies are generally more memory-efficient because they don't replicate the entire data structure.
- Shallow copies are used when you want to create a new object that shares some or all of its data with the original.

**Example**:

```cpp
#include <iostream>
#include <string>

class ShallowCopyExample {
public:
    ShallowCopyExample(const std::string& data) : data_(data) {}

    ShallowCopyExample(const ShallowCopyExample& other) : data_(other.data_) {}

    void printData() {
        std::cout << data_ << std::endl;
    }

private:
    std::string data_;
};

int main() {
    ShallowCopyExample original("Original Data");
    ShallowCopyExample shallowCopy(original);

    original.printData(); // Output: Original Data
    shallowCopy.printData(); // Output: Original Data

    // Modifying shallowCopy affects original
    shallowCopy.printData(); // Output: New Data
    original.printData(); // Output: New Data

    return 0;
}
```

## Illustration

Suppose you have an object `A` that contains a reference to another object `B`. When you make a deep copy of `A`, you create a new object `A'` and also deep copy `B`, creating a new object `B'`. The two resulting data structures (`A'` and `B'`) are entirely independent of the original (`A` and `B`).

In contrast, if you make a shallow copy of `A`, you create a new object `A'`, but it still references the same object `B`. Any changes made to `B` via `A'` will be reflected in the original `B`.

## Wraping Up ^-^
To sum up, the choice between deep copy and shallow copy depends on the desired behavior in your program. Deep copies are used when you want complete independence between objects, while shallow copies are used when you want efficiency and shared data between objects. Thank you for reading this writeup ! 

