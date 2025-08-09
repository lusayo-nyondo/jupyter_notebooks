# The Index-Pointer Approach to Data Structures and Algorithms
This mental model provides an intuitive, hierarchical taxonomy for understanding data structures and algorithms. The core idea is to build a conceptual framework from the ground up, starting with low-level data models and progressing to high-level algorithmic strategies.

## 1. Foundational Data Models
At the lowest level, all data is organized using one of two fundamental models.

### Index-Based Data Models:
Data is stored in a contiguous block of memory. The size is fixed, and elements can be accessed instantly (random access) by their position (index). The quintessential example is an array.

### Pointer-Based Data Models:
Data is stored non-contiguously. The size is dynamic, and elements are accessed sequentially by following "pointers" from one element to the next. The classic example is a linked list.

## 2. Abstract Data Types (ADTs)
ADTs are the logical representations of data that abstract away the underlying data model. They define the behavior and rules for a data structure. ADTs are divided into two main categories:

### Linear ADTs:
Organize data in a sequence, such as arrays, strings, linked lists, stacks, and queues.

### Non-Linear ADTs:
Organize data in a hierarchical or networked fashion, such as hash maps, trees, and graphs.

## 3. Algorithmic Techniques
An algorithm is an ordered set of fundamental operations orchestrated by high-level strategies to solve a problem.

### a. Fundamental Operations
These are the three basic, atomic actions of all algorithms:

### Navigation
The process of traversing a data structure to visit its elements. This can be linear (using single or multi-pointers) or non-linear (hierarchical or network traversal).

### Querying
The act of inspecting data to get an answer. There are two types:

#### Direct Queries
Rely on a stored property of the data structure for instant retrieval (e.g., getting the size of an array).

#### Computed Queries
Require navigation or computation to get an answer (e.g., finding an element in an unsorted array).

### Computation
The process of deriving a new value or data structure from existing data. It's broken down by its logic:

#### Primitive:
Basic math and logic.

#### Algorithmic:
Fixed, predetermined steps (e.g., sum()).

#### Heuristic:
Decision-making at each step (e.g., a greedy algorithm).

### b. Optimization Strategies
These are the high-level approaches to optimize any sort of algorithm.

#### Precomputation
Performing work ahead of time to build an optimized ADT, making future operations faster (e.g., sorting an array for a binary search).

#### Iterative Refinement
A problem-solving strategy that repeatedly applies fundamental operations to narrow down a solution. It can be implemented using an iterative method (loops) or a recursive method (the call stack).