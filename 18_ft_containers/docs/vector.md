# Vector

## Description

Sequence container that encapsulates dynamic size arrays.

- Elements can be accessed not only through iterators, but also using offsets to regular pointers to elements. This means that a pointer to an element of a vector may be passed to any function that expects a pointer to an element of an array.

- Storage of the vector is handled automatically, being expanded as needed. Storage of the vector is handled automatically, being expanded as needed.

- A vector reallocates only when the additional memory is exhausted

## Member types

| Name                   | Description                             | Public |
| ---------------------- | --------------------------------------- | ------ |
| value_type             | T                                       | ✅     |
| allocator_type         | Allocator                               | ✅     |
| size_type              | `unsigned int` (`std::size_t`)          | ✅     |
| difference_type        | `int` (`std::ptrdiff_t`)                | ✅     |
| reference              | value_type&                             | ✅     |
| const_reference        | `cons value_type&`                      | ✅     |
| pointer                | `Allocator::pointer`                    | ✅     |
| const_pointer          | `Allocator::const_pointer`              | ✅     |
| iterator               |                                         | ✅     |
| const_iterator         |                                         | ✅     |
| reverse_iterator       | `std::reverse_iterator<iterator>`       | ✅     |
| const_reverse_iterator | `std::reverse_iterator<const_iterator>` | ✅     |

## Member functions

| Name          | Description             | To implement |
| ------------- | ----------------------- | ------------ |
| constructor   | constructs the `vector` | ✅           |
| destructor    | destructs the `vector`  | ✅           |
| `operator=`   | assigns values          | ✅           |
| assign        | assigns values          | ✅           |
| get_allocator | returns the allocator   | ✅           |

### Element access

| Name       | Description                      | To implement |
| ---------- | -------------------------------- | ------------ |
| at         | access element + bounds checking | ✅           |
| operator[] | acess element                    | ✅           |
| front      | access first element             | ✅           |
| back       | access last element              | ✅           |
| data       | direct access to underlying data | ✅           |

### Iterators

| Name               | Description                   | To implement |
| ------------------ | ----------------------------- | ------------ |
| begin              | iterator to beginning         | ✅           |
| begin              | iterator to end               | ✅           |
| rbegin             | reverse iterator to beginning | ✅           |
| rend               | reverse iterator to end       | ✅           |
| constant iterators | same but constant             | ❌           |

### Capacity

| Name          | Description                                                  | To implement |
| ------------- | ------------------------------------------------------------ | ------------ |
| empty         | check if empty                                               | ✅           |
| size          | number of elements                                           | ✅           |
| max_size      | max number of elements                                       | ✅           |
| reserve       | reserves storage                                             | ✅           |
| capacity      | number of element can be held in currently allocated storage | ✅           |
| shrink_to_fit | free unused memory                                           | ❌           |

### Modifiers

| Name         | Description                      | To implement |
| ------------ | -------------------------------- | ------------ |
| clear        | clear contents                   | ✅           |
| insert       | insert elements                  | ✅           |
| erase        | erase elements                   | ✅           |
| push_back    | add element to end               | ✅           |
| pop_back     | remove last element              | ✅           |
| resize       | change number of elements stored | ✅           |
| emplace_back | construct in-place at end        | ❌           |
| emplace      | construct in-place               | ❌           |

### Non-member functions

Lexicographical comparison

- `==`
- `!=`
- `<` + `<=`
- `>` + `>=`
