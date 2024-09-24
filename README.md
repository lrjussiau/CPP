
# CPP Piscine - C++ Programming Bootcamp

## Description

The *CPP Piscine* is an intensive C++ programming bootcamp at 42 school designed to help students master the fundamental and advanced features of C++ programming. This series of projects and exercises provides in-depth coverage of object-oriented programming (OOP), memory management, templates, and advanced C++ features. It is divided into two parts, each focusing on specific aspects of C++.

## Part 1 - Foundations of C++ Programming

### Objectives

- Learn the syntax and structure of C++.
- Understand memory management, pointers, and references.
- Explore basic object-oriented programming (OOP) principles.
- Implement basic classes and inheritance.
- Develop familiarity with file streams and I/O operations.

### Key Topics

1. **C++ Syntax and Basics**
   - Variables, data types, control structures.
   - Functions, overloading, default arguments.

2. **Pointers and References**
   - How memory is managed in C++.
   - Understanding pointers, references, and the differences between them.

3. **Classes and OOP Concepts**
   - Introduction to classes, constructors, destructors.
   - Basic inheritance, encapsulation, and polymorphism.

4. **Operator Overloading**
   - Overloading basic operators for custom classes.

5. **File I/O**
   - Reading and writing to files using file streams (`fstream`).

## Part 2 - Advanced C++ Programming

### Objectives

- Master advanced object-oriented programming concepts.
- Understand dynamic memory allocation and the role of the heap.
- Learn about templates, exceptions, and the STL (Standard Template Library).
- Explore design patterns and code reuse techniques.

### Key Topics

1. **Memory Management**
   - Dynamic memory allocation using `new` and `delete`.
   - RAII (Resource Acquisition Is Initialization) for managing resources.

2. **Advanced OOP**
   - Multiple inheritance and abstract classes.
   - Virtual functions and overriding.

3. **Templates and the STL**
   - Creating and using function and class templates.
   - Introduction to STL containers (vectors, lists, maps) and algorithms.

4. **Exception Handling**
   - Handling exceptions using `try`, `catch`, and `throw`.
   - Best practices for error handling in large applications.

5. **Design Patterns**
   - Introduction to design patterns such as Singleton, Factory, and Observer.
   - How to implement reusable and efficient C++ code.

## Project Workflow

Each part of the *CPP Piscine* consists of exercises and larger projects designed to solidify your understanding of C++. Some of the core projects include:

1. **PhoneBook Project** (Part 1)
   - A simple contact book application that allows the user to add, view, and search for contacts. This project tests your understanding of basic classes and memory handling in C++.

2. **Fixed-Point Number** (Part 2)
   - A project where you will implement a class to represent numbers with fixed-point precision, diving into operator overloading and deep memory handling.

3. **Abstract Classes & Interfaces** (Part 2)
   - Implement classes that make use of abstract classes and polymorphism to manage a collection of objects.

4. **Template Containers** (Part 2)
   - A project focused on creating custom template-based containers, similar to STL containers, and exploring the benefits of templates.

## Installation and Setup

To get started with the projects, you'll need:

1. A working C++ compiler like `g++`.
2. A proper development environment, which could be set up by cloning the project repository:

```bash
git clone https://github.com/your-repo/cpp-piscine.git
cd cpp-piscine
make
```

## Compiling and Running

For each exercise and project, the compilation steps will be provided. Typically, you can compile individual C++ files using:

```bash
g++ -Wall -Wextra -Werror -std=c++98 file.cpp -o output
```

Then run the resulting program:

```bash
./output
```

## Testing and Validation

Test each project thoroughly to ensure correctness. Example:

```bash
./phonebook
```

Test with various inputs, ensuring no memory leaks (use tools like `valgrind` for validation).

## Error Handling

Each project and exercise should include proper error handling. Catch exceptions where necessary and ensure that no resources (memory, file handles) are leaked.

## Author

- **Louis** - 42 Lausanne Student
