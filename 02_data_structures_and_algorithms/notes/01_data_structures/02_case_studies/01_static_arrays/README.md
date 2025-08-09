Static Array: ADT Definition
A Static Array is a foundational, linear ADT. It is defined by its core characteristics and the operations it supports.

1. Underlying Storage Model
A Static Array is a quintessential example of an Index-Based Data Model. It relies on a contiguous block of memory where elements of the same size are stored sequentially. This fixed, ordered arrangement is what gives it its unique properties.

2. Constraints
The Static Array ADT imposes two primary constraints:

Fixed Size: The size of the array is set when it is created and cannot be changed. This is a direct consequence of its index-based storage model.

Homogeneity: All elements in a static array must be of the same data type, and thus, the same size. This allows for the precise memory address calculations that define its performance.

3. Operations
Due to its storage model and constraints, a Static Array primarily supports the following operations:

a. Access and Retrieval (Direct Query)
The most defining operation of a static array is its ability to access any element directly by its index.

get(index): Returns the value at a specified index. This is a direct query because the memory address can be calculated instantly using the formula: start_address + index * element_size.

set(index, value): Updates the value at a specified index. This is also a direct, constant-time operation.

b. Navigation
traverse(): Iterates through all elements from the beginning to the end. This is a form of linear navigation, typically performed using a single pointer or index.

c. Insertion and Deletion (Inefficient)
While possible, inserting or deleting an element from a static array is generally an expensive process due to the fixed-size constraint.

insert(index, value): To insert a new element, you must first shift all subsequent elements to make room, and then place the new element. This can involve many data movements.

delete(index): To delete an element, you must shift all subsequent elements back to fill the empty space.

These operations are not efficient because they violate the array's contiguous memory constraint and require moving many elements, often leading to a complete reallocation and copy if the array needs to be resized. This is where other data structures, like linked lists, excel.