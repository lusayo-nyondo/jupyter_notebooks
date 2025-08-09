# The Index-Pointer Approach to an Intuitive Understanding of Data Structures and Algorithms

These are my notes and exercises on my own mental model for data structures and algorithms. This mental model provides a conceptual framework for understanding data structures and algorithms, designed to build intuition before delving into formal analysis. The core idea is to organize all related concepts into a clear, hierarchical taxonomy.

## 1. Foundational Data Models
The most fundamental concept is the Data Model, which defines how a computer groups related items. There are two primary types:

### a. Index-Based Data Models.
A data model where the size is fixed and known beforehand. The position of an element can be inferred directly from its index. The primary operation is random access, allowing you to retrieve any element in constant time. A classic example is an array.

### b. Pointer-Based Data Models.
A data model where the size is not known until all elements are inspected. An element's position can only be inferred by following a link or "pointer" from a previous element. The primary operation is sequential access, which requires traversing the structure from a starting point. A classic example is a linked list.

## 2. Abstract Data Types (ADTs)
An Abstract Data Type (ADT) is a logical representation of a data model. It defines a set of behaviors and constraints on how data is organized and accessed, independent of the underlying implementation. ADTs serve as a contract, specifying what operations are available without revealing how they are performed.

We have two major categories:

### a. Linear ADTs

These organize data in a logical sequence.

    Examples include: Arrays, Strings, Linked Lists: ADTs that model sequential collections of data.

Stacks and Queues: ADTs that enforce specific access patterns (LIFO for stacks, FIFO for queues).

### Non-Linear ADTs

These organize data in a hierarchical or networked fashion.

    Hash Maps and Hash Sets: These ADTs use a hash function to map keys to values, enabling near-constant time lookups.
    
    Trees and Heaps: Hierarchical ADTs that model parent-child relationships. Heaps are a specialized tree with a specific ordering property.
    
    Graphs: ADTs that model complex networks of interconnected nodes.

## 3. Algorithmic Techniques

An Algorithm is an ordered set of computational operations performed on an ADT's underlying data to produce a new value or state. This mental model defines two major categories:

### a. Fundamental Operations.

These are the basic, atomic actions performed on data. These include:

#### i. Navigation.
The process of traversing a data structure to visit its elements. This can be linear (e.g., using a single pointer on an array) or non-linear (e.g., traversing a tree).

#### ii. Querying.
The act of inspecting data to get an answer, often a boolean, a specific value, or a range of values.

#### iii. Computation: The process of deriving a new value from existing data, ranging from primitive operations (e.g., 1+1=2) to complex heuristic computations (e.g., greedy algorithms).

### b. Implementation Strategies for Querying, Navigation, and Computation.

These are technical approaches for performing query, navigation, and computation operations. The goal of these is to gain:

#### i. Stored Properties

Leveraging inherent properties of the data structure for a quick result (e.g., getting the size of an array).

#### ii. Precomputation

Performing work ahead of time to make future operations faster (e.g., sorting an array to prepare for a binary search).

#### iii. Iterative Refinement

A strategy that repeatedly applies computations on a dataset to narrow down a solution, which can be implemented using either an iterative method (e.g., a for loop with explicit state) or a recursive method (e.g., using the call stack for implicit state management).