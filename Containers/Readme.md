# Containers

## Sequence Containers
1. Vectors

A __*vector*__ manages its elements in a dynamic way. It enables random access by the correcponding index of elements. Appending and removing elements at the end of the array is very fast. It doesn't provide 'push_front()' function.

1. Deques

A __*deque*__ also manages its elements in a dynamic way and enables random access, but it is useful for bi-direction(front and end) appending and removing elements. It provides 'push_front()' function.

3. Arrays

An __*array*__ manages its elements in an array of fixed size, which is different from vectors and deques. Therefore, the number of elements also a part of the type of an array.

4. Lists

A __*list*__ is implemented as a doubly linked list of elements, which means that each element has its own segment of memoey and refers to its predecessor and its successor. It doesn't provide random access. To access the 5th element, we have to follow the chain of elements' links.

5. Forward Lists

Since C++11, *forward lists* are provided as a singly linked list. Each element refers only to its successor. Therefore, it doesn't support functions which move backword or would cause a performance penalty.

---
## Associative Containers