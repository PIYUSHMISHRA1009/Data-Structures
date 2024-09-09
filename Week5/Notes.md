**Stack Data Structure**

A Stack is a linear data structure that follows a particular order in which the operations are performed. 
The order may be LIFO(Last In First Out) or FILO(First In Last Out). 
LIFO implies that the element that is inserted last, comes out first and FILO implies that the element that is inserted first, comes out last.

**What is Stack Data Structure?**
Stack Data Structure is a linear data structure that follows LIFO (Last In First Out) Principle , so the last element inserted is the first to be popped out. In this article, we will cover all the basics of Stack, Operations on Stack, its implementation, advantages, disadvantages which will help you solve all the problems based on Stack.

**LIFO(Last In First Out) Principle in Stack Data Structure:**

This strategy states that the element that is inserted last will come out first. You can take a pile of plates kept on top of each other as a real-life example. The plate which we put last is on the top and since we remove the plate that is at the top, we can say that the plate that was put last comes out first.

**Representation of Stack Data Structure:**

Stack follows LIFO (Last In First Out) Principle so the element which is pushed last is popped first.

![image](https://github.com/user-attachments/assets/d3f278a6-d7bf-48c4-b18b-445c0d0be5a6)

**Types of Stack Data Structure:**

Fixed Size Stack : As the name suggests, a fixed size stack has a fixed size and cannot grow or shrink dynamically. If the stack is full and an attempt is made to add an element to it, an overflow error occurs. If the stack is empty and an attempt is made to remove an element from it, an underflow error occurs.

Dynamic Size Stack : A dynamic size stack can grow or shrink dynamically. When the stack is full, it automatically increases its size to accommodate the new element, and when the stack is empty, it decreases its size. This type of stack is implemented using a linked list, as it allows for easy resizing of the stack.

**Basic Operations on Stack Data Structure:**

In order to make manipulations in a stack, there are certain operations provided to us.

**push() to insert an element into the stack**
**pop() to remove an element from the stack**
**top() Returns the top element of the stack.**
**isEmpty() returns true if stack is empty else false.**
**isFull() returns true if the stack is full else false.**

**Push Operation in Stack Data Structure:**
Adds an item to the stack. If the stack is full, then it is said to be an **Overflow condition.**

Algorithm for Push Operation:

->Before pushing the element to the stack, we check if the stack is full .
->If the stack is full (top == capacity-1) , then Stack Overflows and we cannot insert the element to the stack.
->Otherwise, we increment the value of top by 1 (top = top + 1) and the new value is inserted at top position .
->The elements can be pushed into the stack till we reach the capacity of the stack.

(https://media.geeksforgeeks.org/wp-content/uploads/20240606180844/Push-Operation-in-Stack-(1)-1024.webp)

**Pop Operation in Stack Data Structure:**

Removes an item from the stack. The items are popped in the reversed order in which they are pushed. If the stack is empty, then it is said to be an Underflow condition.

**Algorithm for Pop Operation:**

Before popping the element from the stack, we check if the stack is empty .
If the stack is empty (top == -1), then Stack Underflows and we cannot remove any element from the stack.
Otherwise, we store the value at top, decrement the value of top by 1 (top = top – 1) and return the stored top value.


https://media.geeksforgeeks.org/wp-content/uploads/20240606180943/Pop-Operation-in-Stack-(1)-1024.webp

**Top or Peek Operation in Stack Data Structure:**

Returns the top element of the stack.

**Algorithm for Top Operation:**

Before returning the top element from the stack, we check if the stack is empty.
If the stack is empty (top == -1), we simply print “Stack is empty”.
Otherwise, we return the element stored at index = top .

![image](https://github.com/user-attachments/assets/89d8ded3-9905-4333-91fa-940ae8c4a155)

**isEmpty Operation in Stack Data Structure:**
Returns true if the stack is empty, else false.

**Algorithm for isEmpty Operation:**

Check for the value of top in stack.
If (top == -1) , then the stack is empty so return true .
Otherwise, the stack is not empty so return false .

https://media.geeksforgeeks.org/wp-content/uploads/20240606181101/isEmpty-Operation-in-Stack-(1)-1024.webp

**isFull Operation in Stack Data Structure:**
Returns true if the stack is full, else false.

**Algorithm for isFull Operation:**

Check for the value of top in stack.
If (top == capacity-1), then the stack is full so return true.
Otherwise, the stack is not full so return false.

https://media.geeksforgeeks.org/wp-content/uploads/20240606181147/isFull-Operation-in-Stack-(1)-1024.webp

**Implementation of Stack Data Structure:**
The basic operations that can be performed on a stack include push, pop, and peek. There are two ways to implement a stack –

-Using Array
-Using Linked List

-**In an array-based implementation, the push operation is implemented by incrementing the index of the top element and storing the new element at that index. The pop operation is implemented by returning the value stored at the top index and then decrementing the index of the top element.**

-**In a linked list-based implementation, the push operation is implemented by creating a new node with the new element and setting the next pointer of the current top node to the new node. The pop operation is implemented by setting the next pointer of the current top node to the next node and returning the value of the current top node.**




