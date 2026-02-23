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

##  Example Code

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl; // 30

    st.pop();

    cout << "Top after pop: " << st.top() << endl; // 20
    cout << "Stack size: " << st.size() << endl; // 2
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}

```


