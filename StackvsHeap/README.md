# Stack vs Heap


---



<h2>Table of Contents</h2>
<ol>
  <li><a href="#heap">Heap</a></li>
  <li><a href="#stack">Stack</a></li>
  <li><a href="#stack-vs-heap">Stack vs Heap</a></li>
  <li><a href="#real-life-problem">Real Life Problem</a></li>
</ol>



---


## What is Heap ?

In computer science, the heap is a region of memory used for dynamic memory allocation. It is a region of memory that is not managed automatically by the operating system, but rather by the programmer using the programming language's memory allocation functions.

The heap is different from the stack, which is a region of memory used for automatic memory allocation of function call frames and local variables.

In the heap, memory can be allocated and deallocated at runtime as needed. Memory allocation in the heap is done using functions such as `malloc()` and `new` in C and C++, respectively. The memory allocated on the heap is not automatically reclaimed when it is no longer needed, and it is the programmer's responsibility to free the memory using functions such as `free()` or `delete`.

One of the advantages of using the heap is that it allows for flexible memory allocation and deallocation at runtime. However, improper use of the heap, such as not freeing allocated memory or accessing memory that has already been freed, can lead to memory leaks and program crashes.

It's worth noting that the heap is not the same as the "heap data structure," which is a specific data structure used to implement priority queues and heap sort algorithms.

## What is Stack ? 

In computer science, a stack is an abstract data type that represents a collection of elements that supports two main operations:

* **Push operation**: Adds an element to the top of the stack.
* **Pop operation**: Removes the top element from the stack.
* A stack is also called a **Last-In-First-Out (LIFO)** data structure, which means that the element that was last pushed onto the stack will be the first one to be popped off.

A stack is typically implemented as a contiguous block of memory, where the top element of the stack is located at a fixed position. When a new element is pushed onto the stack, it is placed on top of the current top element, and the top position is incremented. Similarly, when an element is popped off the stack, the top position is decremented to the next element below.

Stacks are commonly used in computer science and programming for a variety of applications, such as:

1. Evaluating expressions in compilers and interpreters.
2. Keeping track of function calls and returns in program execution.
3. Implementing undo and redo functionality in user interfaces.
4. Parsing and manipulating data in algorithms, such as depth-first search and backtracking.

## Stack vs Heap

In computer science, the **`heap`** and the **`stack`** are two different regions of memory used for different purposes. The main differences between the two are:

* **Allocation:** The **`stack`** is used for automatic memory allocation of function call frames and local variables, while the **`heap`** is used for dynamic memory allocation of objects whose lifetime extends beyond the scope of the function in which they were created.

* **Management**: The **`stack`** is managed automatically by the operating system and the programming language's runtime environment, while the **`heap`** is managed manually by the programmer using memory allocation functions such as malloc() and new.

* **Access**: Accessing memory on the **`stack`** is faster than accessing memory on the **`heap`**, as the **`stack`** is a contiguous block of memory that is allocated and deallocated in a strict last-in-first-out (LIFO) order. The **`heap`**, on the other hand, is a more flexible but less organized region of memory that requires more time to allocate and deallocate, and accessing memory on the **`heap`** requires using pointers.

* **Lifetime**: The memory allocated on the **`stack`** is automatically deallocated when the function or block in which it was created exits, while memory allocated on the **`heap`** persists until it is explicitly deallocated by the programmer.

In summary, the **`stack`** is used for temporary storage of data, while the **`heap`** is used for long-term storage of data. The stack is managed automatically and is faster to access, while the `heap` is managed manually and provides more flexibility but is slower to access.



---

## Real Life Problem 

Have you ever used a program or application that crashed due to a memory-related issue, such as a segmentation fault or heap corruption? If so, can you think of a reason why that might have happened?


In a program, the **`stack`** has a limited size, and if too much memory is used for function call frames and local variables, it can cause a **`stack overflow`**. This can happen, for example, if a function calls itself recursively too many times or if there are too many nested function calls.

On the other hand, a **`heap-related`** issue such as a **`memory leak`** or **`heap corruption`** can also cause a program to crash. A memory leak occurs when memory is allocated on the heap but not properly deallocated, leading to a gradual increase in memory usage over time. Heap corruption can occur if memory is accessed outside of its allocated bounds or if memory is freed twice. Both of these issues can cause a program to behave unpredictably or crash.




