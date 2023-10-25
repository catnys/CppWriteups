
# C++ Smart Pointers: std::unique_ptr and std::shared_ptr
## Intro
C++ provides smart pointers, such as std::unique_ptr and std::shared_ptr, to manage dynamically allocated objects. These smart pointers automate memory management, ensuring proper deallocation of resources and stuff.

## std::unique_ptr
* Exclusive Ownership: std::unique_ptr represents exclusive ownership, meaning only one pointer can own the object.
* Ownership Transfer: Ownership can be transferred using std::move, but the object cannot be directly shared.
* Overhead: Lower overhead compared to std::shared_ptr.

Example:
```cpp
std::unique_ptr<int> uniquePtr = std::make_unique<int>(42);
*uniquePtr = 200;  // Modify the object via the pointer.
```
## std::shared_ptr
* Shared Ownership: std::shared_ptr enables shared ownership, allowing multiple pointers to share an object.
* Ownership Transfer: Easily transfer ownership and create multiple shared pointers sharing the same object.
* Overhead: Higher overhead due to reference counting.

Example:
```cpp
std::shared_ptr<int> sharedPtr1 = std::make_shared<int>(42);
std::shared_ptr<int> sharedPtr2 = sharedPtr1;
int referenceCount = sharedPtr1.use_count();  // Get the reference count.

sharedPtr2.reset();  // Reset one of the shared pointers.
bool isValid = (sharedPtr2 != nullptr);  // Check if a shared pointer is valid.
bool isUnique = sharedPtr1.unique();  // Check if a shared pointer is the unique owner.
```
---
## FAQ
1. What's the difference between std::unique_ptr and std::shared_ptr?

`std::unique_ptr provides exclusive ownership and has lower overhead.
std::shared_ptr enables shared ownership and uses reference counting, resulting in higher overhead.`

2. Can I change the value of an object pointed to by a std::unique_ptr?

`Yes, you can change the object's value using the pointer (e.g., *uniquePtr = 200;).`

3. Can I use a std::shared_ptr to manage multiple std::unique_ptr instances?

`No, you cannot directly use a std::shared_ptr to manage multiple std::unique_ptr instances. Shared ownership is a feature of std::shared_ptr.`

4. How do I transfer ownership from a std::unique_ptr to a std::shared_ptr?

`u can use the std::shared_ptr constructor or std::move to transfer ownership.`
5. How do I get the reference count of a std::shared_ptr?

`U can use the use_count() method.`

6. How can I check if a std::shared_ptr is valid and not null?

`Use an if condition (e.g., if (sharedPtr != nullptr) or if (sharedPtr)).`

7. How can I check if a std::shared_ptr is the unique owner of the object?

`Use the unique() method. :)`

---

```cpp
#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass(int value) : data(value) {}

    void display() {
        std::cout << "Value: " << data << std::endl;
    }

private:
    int data;
};

int main() {
    // Create a shared pointer to a MyClass object
    std::shared_ptr<MyClass> sharedPtr1 = std::make_shared<MyClass>(42);
    
    // Create more shared pointers sharing ownership of the same object
    std::shared_ptr<MyClass> sharedPtr2 = sharedPtr1;
    std::shared_ptr<MyClass> sharedPtr3 = sharedPtr1;

    // Access and use the object via sharedPtr1
    sharedPtr1->display();

    // Access and use the object via sharedPtr2
    sharedPtr2->display();

    // Access and use the object via sharedPtr3
    sharedPtr3->display();

    // Get the reference count
    int referenceCount = sharedPtr1.use_count();
    std::cout << "Reference Count: " << referenceCount << std::endl;

    // Reset one of the shared pointers
    sharedPtr2.reset();
    int newReferenceCount = sharedPtr1.use_count();
    std::cout << "Reference Count after reset: " << newReferenceCount << std::endl;

    // Check if the shared pointer is valid
    if (sharedPtr2) {
        std::cout << "sharedPtr2 is valid." << std::endl;
    } else {
        std::cout << "sharedPtr2 is not valid." << std::endl;
    }

    // Check if the shared pointer is the unique owner
    if (sharedPtr1.unique()) {
        std::cout << "sharedPtr1 is the unique owner." << std::endl;
    } else {
        std::cout << "sharedPtr1 is not the unique owner." << std::endl;
    }

    return 0;
}
```
In this extended example:

* We've added a MyClass class to demonstrate the use of a custom class with std::shared_ptr.
* Three shared pointers (sharedPtr1, sharedPtr2, and sharedPtr3) can be accessed and used the object.
* We can use the use_count() method to get the reference count, showing how many shared pointers are sharing ownership of the object.
* Reseting one of the shared pointers (sharedPtr2) using the reset() method, which reduces the reference count.
* Checking if a shared pointer is valid using an if condition. A shared pointer is considered valid if it's not null.
* We can check if a shared pointer is the unique owner using the unique() method. If it returns true, it means that there is only one shared pointer owning the object.

> With std::shared_ptr, you can have multiple std::shared_ptr instances that all share ownership of the same dynamically allocated object in the heap. This allows multiple parts of your code to access and manage the same object, and the object will only be deleted when the last std::shared_ptr pointing to it goes out of scope or is explicitly reset. It provides a way to achieve shared ownership of a resource.

