# CPP_STL

**Reference**
- Nicolai Josuttis, *C++ Standard Library, The: A Tutorial and Reference*, 2nd Ed.
- 공동환, *뇌를 자극하는 C++ STL*
---
## Containers

### Sequence Containers

This type of containers has its own sorting strategy determined by inserting order.

#### **Vectors**

A __*vector*__ manages its elements in a dynamic way. It enables random access by the correcponding index of elements. Appending and removing elements at the end of the array is fast. It uses a memory block to contain elements. It doesn't support 'push_front()' function.

It has a _capacity()_ function as a member function, and it is a unique property of vector container. Vector reallocate memory enough to contain several more elements. My compiler reallocate memory two times more than the last reallocation.

- __remarkable member functions__ : size(), capacity(), max_size(), begin(), end(), rbegin(), rend(), reserve(), push_back(), pop_back(), resize(), clear(), empty(), swap(), front(), back(), assign(), insert(), erase()

** calling insert(), erase() uses a lot of resources... so it'd be better to choose another container if your system does so.

#### **Deques**

A __*deque*__ is a very similar to vector, which manages its elements in a dynamic way and enables random access. It is useful for bi-direction(front and end) appending and removing elements. Different from a vector, it uses several memory blocks to contain elements. It doesn't change memory address, but add another block to sustain added elements. It provides 'push_front()' function.

Due to its memory allocation strategy, insert() and erase() perform way better than vector.

- __remarkable member functions__ : same with vector's... +) push_front(), pop_front()

#### **Lists**

A __*list*__ is implemented as a doubly linked list of elements, which means that each element has its own segment of memory and refers to its predecessor and its successor. It doesn't provide random access. To access the 5th element, we have to follow the chain of elements' links.

- __remarkable member functions__ : same with deque's... +) splice(), merge(), unique(), sort(), remove()... -) [] operator, at()

#### **Arrays**

An __*array*__ manages its elements in an array of fixed size, which is different from vectors and deques. Therefore, the number of elements also a part of the type of an array.

#### **Forward Lists**

Since C++11, *forward lists* are provided as a singly linked list. Each element refers only to its successor. Therefore, it doesn't support functions which move backword or would cause a performance penalty.

### Associative Containers

Associative containers sort their elements automatically according to a certain criterion which is pre-determined. Sets and multisets use values, and maps and multimaps use keys to sort the values.

#### **Sets and Multisets**
  
A __*set*__ is a collection where all the elemnts are sorted according to their own values. __*Multiset*__ is same with a set except it allows duplicates.

Set consists of key values. it doesn't support push_back(), push_support(), front(), back(), pop_back(), pop_front()... It can add a key value by using insert(). The pre-determined sorting criteria is less.

__All the associative containers(set, multiset, map, multimap) provide the same interface and member functions...__

#### **Maps and Multimaps**

a __*map*__ is a key/value pair. A __*multimap*__ allows duplicates(a key can be assigned to different values), and newly inserted elements are inserted at the end of equivalent elements that multimaps already contain.

### Unordered Containers

In unordered containers, order is not determined and it is not important. The fact that there is a specific element is the only important.

- Unordered sets/multisets, unordered maps/multimaps

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

--> vector/deque - support 1~5; list/(multi)set/(multi)map - support 1~4;

### Operators
- __Operator *__ returns the element of the current position. We can access members of the element by using ->.
- __Opeartor ++__ lets the iterator step forward to the next element.
- __Operators ==__ and __!=__ returns whether two iterators represent the same position.
- __Operator =__ assigns an iterator.

### Functions
- __begin()__ returns an iterator that represents the beginning of the elements in the container.
- __end()__ returns an iterator that represents the end of the elements in the container. The end is the position behind the last element.

These functions define half-open range that includes the first element but excludes the last... there are two key advantages of it: 1) it makes for loop convenient. 2) it avoids special handling for empty ranges... because for empty ranges, begin() is equal to end().

---
## Algorithms

### Nonmodifying algorithms

Nonmodifying algorithms don't change elements...

- **return iter** : adjacent_find(); find(), find_if(); find_end(), search(), search_n(); find_first_of(); max_element(), min_element(); mismatch(); 
- **return bool** : equal(); lexicographical_compare(); 
- **return int** : count(), count_if(); 
- **others** : for_each(); 

### Modifying algorithms

These algorithms change elements of a container. It works in 'overwrite mode'... it means that to make it work, there should be pre-allocated memory...

- **return iter** : copy(), copy_backward(); transform()...it works based on the return value of the function object. its inputs are iterators from 2 containers.; merge(); replace_copy(), replace_copy_if(); 
- **others** : fill(), fill_n(); for_each()...it ignores the return value of the function object, just call the function based on each element. Its input is each element of a container according to the input iterator; generate(), generate_n()...it works based on the return value of the function object; iter_swap(); replace(), replace_if(); swap_ranges(); 

### Removing algorithms

These are special cases of modifying algorithms. These don't change the size of the container, but these just overwrite the memory by other values...

- **return iter** : remove(), remove_if(), remove_copy(), remove_copy_if(); unique(); 
- **others** : erase();

### Mutating algorithms

These change the order of the elements.

- **return iter** : partition(), stable_partition(); 
- **others** : next_permutation(), prev_permutation(); random_shuffle(); reverse(), reverse_copy(); rotate()

### Sorting algorithms

These algorithms are special cases of mutating algorithms. These change the order of elements and sort those based on a specific standard.

- **heap related** : make_heap(), push_heap(), pop_heap(), sort_heap()... heap is a binary tree data structure.
- **others** : nth_element(); sort(), stable_sort(), partial_sort(), partial_sort_copy(); 

### Sorted range algorithms

These algorithms work only on sorted range. In these algorithms, it doesn't use == but !(<) && !(>) in judging equivalance.

- **return iter** : lower_bound(), upper_bound(); equal_range()...it returns pair\<iter, iter>;  merge(); set_union(), set_intersection(), set_difference(), set_symmetric_difference();
- **return bool** : binary_search(); includes();
- **others** : inplace_merge();

### Numeric algorithms

There algorithms are defined in \<numeric> header. These are related to numerical calculations.

- **return iter** : adjacent_difference(); partial_sum();
- **return int, double, ...** : accumulate(); inner_product(); 

---

## Function Objects

Function objects, a.k.a. functor, are objects overloading operator().

### General Function Objects
1. Arithmetic
- plus<T> : binary operator +
- minus<T> : binary operator -
- multiplies<T> : binary operator *
- divides<T> : binary operator /
- modulus<T> : binary operator %
- negate<T> : unary operator -
2. Comparison
- equal_to<T> : binary operator ==
- not_equal_to<T> : binary operator !=
- less<T> : binary operator <
- less_equal<T> : binary operator <=
- greater<T> : binary operator >
- greater_equal<T> : binary operator >=
3. Logical
- logical_and<T> : binary operator &&
- logical_or<T> : binary operator ||
- logical_not<T> : unary operator !

### Function Adaptors
1. Binder
- bind1st : fix the first argument of binary function
- bind2nd : fix the second argument of binary function
2. Nagator
- not1 : unary predicate
- not2 : binary predicate
3. Function Adaptors
- ptr_fun : global function to  -> functor
- mem_fun(by the object), mem_fun_ref(by the address of the object) : member function -> functor