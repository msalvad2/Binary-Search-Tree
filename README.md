# Binary Search Tree (BST) Project

This project is a **C++ implementation of a Binary Search Tree (BST)**, developed as part of a data structures course.  
It demonstrates recursion, dynamic memory management, and object-oriented design in C++.

## Features
- Insert nodes into the tree
- Search for values in the tree
- In-order, pre-order, and post-order traversals
- Proper destructor for memory cleanup
- Stores custom `Product` objects inside the tree

## Technical Highlights
- Implemented in **C++**
- Demonstrates **recursion** and **pointer-based memory management**
- Uses **separate source/header files** for clean modular design
- Follows best practices for constructors, destructors, and encapsulation

## File Structure
- `bst.h` / `bst.cpp` → Core Binary Search Tree implementation  
- `product.h` / `product.cpp` → Product class used as tree data  
- `main.cpp` → Driver program demonstrating BST functionality  

## How to Compile & Run
```bash
g++ main.cpp bst.cpp product.cpp -o bst
./bst
