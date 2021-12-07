# Containers

## Sequence Containers
- Vectors

A __*vector*__ manages its elements in a dynamic way. It enables random access by the correcponding index of elements. Appending and removing elements at the end of the array is very fast. It doesn't provide 'push_front()' function.

- Deques

A __*deque*__ also manages its elements in a dynamic way and enables random access, but it is useful for bi-direction(front and end) appending and removing elements. It provides 'push_front()' function.

- Arrays

An __*array*__ manages its elements in an array of fixed size, which is different from vectors and deques. Therefore, the number of elements also a part of the type of an array.

- Lists

A __*list*__ is implemented as a doubly linked list of elements, which means that each element has its own segment of memoey and refers to its predecessor and its successor. It doesn't provide random access. To access the 5th element, we have to follow the chain of elements' links.

- Forward Lists

Since C++11, *forward lists* are provided as a singly linked list. Each element refers only to its successor. Therefore, it doesn't support functions which move backword or would cause a performance penalty.

---
## Associative Containers

Associative containers sort their elements automatically according to a certain criterion which is pre-determined. Sets and multisets use values, and maps and multimaps use keys to sort the values.

- Sets and Multisets
  
A __*set*__ is a collection where all the elemnts are sorted according to their own values. __*Multiset*__ is same with a set except it allows duplicates. 

- Maps and Multimaps

a __*map*__ is a key/value pair. A __*multimap*__ allows duplicates(a key can be assigned to different values), and newly inserted elements are inserted at the end of equivalent elements that multimaps already contain.

---
## Unordered Containers

In unordered containers, order is not determined and it is not important. The fact that there is a specific element is the only important.

- Unordered sets/multisets, unordered maps/multimaps

---
## Other types...

- Associative arrays : an array whose index is not an integer value.
- String
- C-style arrays
- Containers adapters : stack(LIFO, last-in-first-out), queue(FIFO, first-in-first-out), priority queue