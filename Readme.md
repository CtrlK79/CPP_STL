# CPP_STL

**Reference**
- Nicolai Josuttis, *C++ Standard Library, The: A Tutorial and Reference*, 2nd Ed.
- 공동환, *뇌를 자극하는 C++ STL*
---
## Containers

### Sequence Containers

This type of containers has its own sorting strategy determined by inserting order.

- __Vectors__

A __*vector*__ manages its elements in a dynamic way. It enables random access by the correcponding index of elements. Appending and removing elements at the end of the array is fast. It uses a memory block to contain elements. It doesn't support 'push_front()' function.

It has a _capacity()_ function as a member function, and it is a unique property of vector container. Vector reallocate memory enough to contain several more elements. My compiler reallocate memory two times more than the last reallocation.

__remarkable member functions__ : size(), capacity(), max_size(), begin(), end(), rbegin(), rend(), reserve(), push_back(), pop_back(), resize(), clear(), empty(), swap(), front(), back(), assign(), insert(), erase()

** calling insert(), erase() uses a lot of resources... so it'd be better to choose another container if your system does so.

- __Deques__

A __*deque*__ is a very similar to vector, which manages its elements in a dynamic way and enables random access. It is useful for bi-direction(front and end) appending and removing elements. Different from a vector, it uses several memory blocks to contain elements. It doesn't change memory address, but add another block to sustain added elements. It provides 'push_front()' function.

Due to its memory allocation strategy, insert() and erase() perform way better than vector.

__remarkable member functions__ : same with vector's... +) push_front(), pop_front()

- __Lists__

A __*list*__ is implemented as a doubly linked list of elements, which means that each element has its own segment of memory and refers to its predecessor and its successor. It doesn't provide random access. To access the 5th element, we have to follow the chain of elements' links.

__remarkable member functions__ : same with deque's... +) splice(), merge(), unique(), sort(), remove()... -) [] operator, at()

- __Arrays__

An __*array*__ manages its elements in an array of fixed size, which is different from vectors and deques. Therefore, the number of elements also a part of the type of an array.

- Forward Lists

Since C++11, *forward lists* are provided as a singly linked list. Each element refers only to its successor. Therefore, it doesn't support functions which move backword or would cause a performance penalty.

---
### Associative Containers

Associative containers sort their elements automatically according to a certain criterion which is pre-determined. Sets and multisets use values, and maps and multimaps use keys to sort the values.

- Sets and Multisets
  
A __*set*__ is a collection where all the elemnts are sorted according to their own values. __*Multiset*__ is same with a set except it allows duplicates.

Set consists of key values. it doesn't support push_back(), push_support(), front(), back(), pop_back(), pop_front()... It can add a key value by using insert(). The pre-determined sorting criteria is less.

__All the associative containers(set, multiset, map, multimap) provide the same interface and member functions...__

- Maps and Multimaps

a __*map*__ is a key/value pair. A __*multimap*__ allows duplicates(a key can be assigned to different values), and newly inserted elements are inserted at the end of equivalent elements that multimaps already contain.

---
### Unordered Containers

In unordered containers, order is not determined and it is not important. The fact that there is a specific element is the only important.

- Unordered sets/multisets, unordered maps/multimaps

---
### Other types...

- Associative arrays : an array whose index is not an integer value.
- String
- C-style arrays
- Containers adapters : stack(LIFO, last-in-first-out), queue(FIFO, first-in-first-out), priority queue


---
## Iterators
Though we can process all elements by using a range-based for loop(since C++11), to find a specific element, processing all elements is too expensive. An __*iterator*__ is an object(similar to a smart pointer) to fulfill this need, by representing positions of elements in a container.

Iterator gives users consistent way to access the elements in different containers. Thanks to iterators, an algorithm is independent from a specific container.

There are 5 types:
1. input iterator
2. output iterator
3. forward iterator
4. bidirectional iterator
5. random access iterator

---
### Operators
- __Operator *__ returns the element of the current position. We can access members of the element by using ->.
- __Opeartor ++__ lets the iterator step forward to the next element.
- __Operators ==__ and __!=__ returns whether two iterators represent the same position.
- __Operator =__ assigns an iterator.

---
### Functions
- __begin()__ returns an iterator that represents the beginning of the elements in the container.
- __end()__ returns an iterator that represents the end of the elements in the container. The end is the position behind the last element.

These functions define half-open range that includes the first element but excludes the last... there are two key advantages of it: 1) it makes for loop convenient. 2) it avoids special handling for empty ranges... because for empty ranges, begin() is equal to end().
