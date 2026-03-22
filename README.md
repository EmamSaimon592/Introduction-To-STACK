<p align="center">
  <img src="stack_imam.jpg" alt="stack_imam"/>
</p>

# Stack in C++

This repository demonstrates how to use the **Stack** data structure in **C++** using the Standard Template Library (STL). A stack is a linear data structure that follows the **Last In, First Out (LIFO)** principle.

---

##  What is a Stack?

A **Stack** allows operations at only one end – the **top**. The last element added to the stack is the first to be removed.

**Main operations:**
- `push()` – Add element
- `pop()` – Remove top element
- `top()` – Access top element
- `empty()` – Check if the stack is empty
- `size()` – Get the number of elements

---


#  Stack (DSA) Quiz Questions & Answers

## 1. What is a Stack?
**Answer:**  
A stack is a linear data structure that follows the **LIFO (Last In First Out)** principle.  
The last element inserted is the first one to be removed.

---

## 2. What are the basic operations of a stack?
**Answer:**  
- **Push** → Insert an element into the stack  
- **Pop** → Remove the top element  
- **Peek/Top** → Get the top element without removing it  
- **isEmpty** → Check if the stack is empty  
- **isFull** → Check if the stack is full (for fixed size stack)

---

## 3. What is Stack Overflow and Stack Underflow?
**Answer:**  
- **Stack Overflow** → Happens when we try to push an element into a full stack  
- **Stack Underflow** → Happens when we try to pop from an empty stack  

---

## 4. Where is stack used in real life or programming?
**Answer:**  
- Function calls (Call Stack)  
- Undo/Redo operations  
- Expression evaluation (e.g., postfix, prefix)  
- Parenthesis matching  
- Backtracking algorithms  

---

## 5. Implement Stack using Array in C++

```cpp
#include <iostream>
using namespace std;

#define MAX 5
int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stack[++top] = x;
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << "Popped: " << stack[top--] << endl;
}

void peek() {
    if (top != -1)
        cout << "Top element: " << stack[top] << endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    peek();
    pop();
    peek();
    return 0;
}

---

