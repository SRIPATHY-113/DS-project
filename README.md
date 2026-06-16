# Online Shopping Cart (C-Based CLI Application)

A lightweight command-line interface (CLI) application demonstrating core Data Structures and Algorithms (DSA) concepts in C. The project models an online shopping cart using a dynamic **Singly Linked List** to handle real-time insertions, lookup checks, sequential data traversals, and heap memory deallocations.

---

## 🚀 Key Features

* **Dynamic Inventory Control:** Items are added dynamically at runtime utilizing system heap allocation (`malloc`), overcoming fixed-size limitations of standard primitive arrays.
* **Smart Insertion & Duplication Interception:** Automatically invokes a lookup sub-routine prior to allocation to verify that an Item ID does not already exist inside the session.
* **Optimized Head Insertion:** New cart node attachments complete in $O(1)$ constant time complexity by re-linking the global `cartHead` reference.
* **Targeted Dynamic Deletion:** Traverses active memory blocks safely via tracking pointer nodes (`current` and `previous`), splicing nodes out cleanly without causing orphaned pointer memory breaks.
* **Linear Accumulation Calculations:** Steps through active nodes to aggregate floating-point mathematical product models (`Price × Quantity`) on the fly.

---

## 📦 System Architecture & Stack

* **Language Platform:** C (C99 / C11 Standard)
* **Core Libraries:** * `<stdio.h>` (Standard Input/Output streaming)
  * `<stdlib.h>` (Dynamic allocation routines via `malloc()` / `free()`)
  * `<string.h>` (String manipulations via `strcpy()`)
* **Core Data Structure:** Singly Linked List consisting of nested self-referential tracking structures.

---

## 📐 Data Structure Architecture

The application separates item business attributes from the structural memory plumbing by nesting a data payload structure inside a wrapper node structure:

```c
// Payload structure containing item metadata
typedef struct {  
    int id;  
    char name[50];  
    float price;  
    int quantity;  
} Item;  
 
// Self-referential node structure mapping the linked list layout
typedef struct CartNode {  
    Item item;  
    struct CartNode* next;  
} CartNode;
