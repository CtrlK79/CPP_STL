# Iterators
Though we can process all elements by for using a range-based for loop(since C++11), to find a specific element, processing all elements is too expensive. an __*iterator*__ is an object(similar to a smart pointer) to fulfill this need, by representing positions of elements in a container.

---
## Operators
- __Operator *__ returns the element of the current position. We can access members of the element by using ->.
- __Opeartor ++__ lets the iterator step forward to the next element.
- __Operators ==__ and __!=__ returns whether two iterators represent the same position.
- __Operator =__ assigns an iterator.

---
## Functions
- __begin()__ returns an iterator that represents the beginning of the elements in the container.
- __end()__ returns an iterator that represents the end of the elements in the container. The end is the position behind the last element.

These functions define half-open range that includes the first element but excludes the last... there are two key advantages of it: 1) it makes for loop convenient. 2) it avoids special handling for empty ranges... because for empty ranges, begin() is equal to end().
