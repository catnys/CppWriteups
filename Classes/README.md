# Deep Dive: Classes in C++

## 1. Description
A **Class** in C++ is a user-defined data type that serves as a blueprint for creating objects. It creates a bundle that binds data (attributes/variables) and the functions (methods) that manipulate that data together. This concept is known as **Encapsulation**.

In C++, a `class` is almost identical to a `struct`, with one key difference:
* **Struct:** Members are `public` by default.
* **Class:** Members are `private` by default.

## 2. Real-Life Illustration
Think of a **Car Factory Mold**.

* **The Class (The Mold):** This implies that a car *has* 4 wheels, a color, and an engine. It *can* accelerate and brake. You cannot drive the mold itself.
* **The Object (The Car):** The factory uses the mold to create actual cars (instances). One might be Red, another Blue.
* **Encapsulation:** You drive the car using the steering wheel and pedals (Public Interface). You don't directly inject fuel into the cylinders with a syringe (Private Implementation).

## 3. Technical Analysis
Since you are confident in OOP, let's look at how C++ handles classes at a low level:

### Memory Layout
* **Data:** When you instantiate an object, only its **non-static data members** take up memory size in that specific instance.
* **Functions:** Member functions are **not** stored inside the object. They exist once in the Code Segment (Text Segment) of the memory.
* **Alignment/Padding:** The compiler may add "padding" bytes between variables to align data with the processor's architecture (e.g., aligning integers to 4-byte boundaries), making `sizeof(MyClass)` potentially larger than the sum of its members.

### The `this` Pointer
How does a function know *which* object's data to modify if functions are stored separately?
* The compiler secretly passes a hidden pointer called `this` as the first argument to every non-static member function.
* `obj.func(5)` becomes roughly `func(&obj, 5)` in assembly.

### The Empty Class Size
* An empty class `class Empty {};` has a size of **1 byte** (not 0).
* **Reason:** Every object must have a unique address in memory so that pointers work correctly.

## 4. Technical Code Example

This example demonstrates encapsulation, the `this` pointer usage, and the distinction between interface (public) and data (private).

# Deep Dive: Classes in C++

## 1. Description
A **Class** in C++ is a user-defined data type that serves as a blueprint for creating objects. It creates a bundle that binds data (attributes/variables) and the functions (methods) that manipulate that data together. This concept is known as **Encapsulation**.

In C++, a `class` is almost identical to a `struct`, with one key difference:
* **Struct:** Members are `public` by default.
* **Class:** Members are `private` by default.

## 2. Real-Life Illustration
Think of a **Car Factory Mold**.

* **The Class (The Mold):** This implies that a car *has* 4 wheels, a color, and an engine. It *can* accelerate and brake. You cannot drive the mold itself.
* **The Object (The Car):** The factory uses the mold to create actual cars (instances). One might be Red, another Blue.
* **Encapsulation:** You drive the car using the steering wheel and pedals (Public Interface). You don't directly inject fuel into the cylinders with a syringe (Private Implementation).

## 3. Technical Analysis
Since you are confident in OOP, let's look at how C++ handles classes at a low level:

### Memory Layout
* **Data:** When you instantiate an object, only its **non-static data members** take up memory size in that specific instance.
* **Functions:** Member functions are **not** stored inside the object. They exist once in the Code Segment (Text Segment) of the memory.
* **Alignment/Padding:** The compiler may add "padding" bytes between variables to align data with the processor's architecture (e.g., aligning integers to 4-byte boundaries), making `sizeof(MyClass)` potentially larger than the sum of its members.

### The `this` Pointer
How does a function know *which* object's data to modify if functions are stored separately?
* The compiler secretly passes a hidden pointer called `this` as the first argument to every non-static member function.
* `obj.func(5)` becomes roughly `func(&obj, 5)` in assembly.

### The Empty Class Size
* An empty class `class Empty {};` has a size of **1 byte** (not 0).
* **Reason:** Every object must have a unique address in memory so that pointers work correctly.

## 4. Technical Code Example

This example demonstrates encapsulation, the `this` pointer usage, and the distinction between interface (public) and data (private).

```cpp
#include <iostream>
#include <string>

class Server {
private:
    // Data members are usually private (Encapsulation)
    std::string ipAddress;
    int port;
    bool isRunning;

public:
    // Simple Constructor for initialization
    void init(std::string ip, int p) {
        // 'this' pointer resolves ambiguity between member and parameter
        this->ipAddress = ip;
        this->port = p;
        this->isRunning = false;
    }

    // Public method to modify state
    void start() {
        if (!isRunning) {
            isRunning = true;
            std::cout << "[LOG] Server started at " << ipAddress << ":" << port << "\n";
        }
    }

    // Public method to read state (Getter)
    bool getStatus() {
        return isRunning;
    }
};

int main() {
    // 1. Instantiation (Creating an object on the Stack)
    Server webServer;

    // 2. Accessing Public Interface
    // We cannot access 'webServer.port' directly because it is private.
    webServer.init("192.168.1.1", 8080);
    
    std::cout << "Server Status Before: " << webServer.getStatus() << "\n";
    
    webServer.start();

    std::cout << "Server Status After: " << webServer.getStatus() << "\n";

    // 3. Size demonstration
    std::cout << "Size of Server Object: " << sizeof(webServer) << " bytes\n";
    // Size will be roughly sizeof(string) + sizeof(int) + sizeof(bool) + padding

    return 0;
}
```