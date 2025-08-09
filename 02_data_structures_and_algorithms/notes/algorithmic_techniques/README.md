# Algorithmic Techniques In a NutShell

1. Fundamental Operations
    These are the basic, atomic actions you perform on data. Think of them as the verbs of algorithms.
    
    a. Navigation 🧭
        The process of traversing a data structure to visit its elements. This is about movement and access.
        
            - Linear Navigation: Moving sequentially through elements.
                - Single-Pointer: Using a single index or reference to move one element at a time (e.g., for loop on an array).
                - Multi-Pointer: Using two or more indices or references to move through the data simultaneously (e.g., fast and slow pointers in a linked list, low and high indices in a binary search).
        
            - Non-Linear Navigation: Moving through hierarchical or networked structures.
                - Hierarchical Traversal: Moving between a parent and its children (e.g., traversing a tree). This is the underlying principle for algorithms like Depth-First Search (DFS) and Breadth-First Search (BFS), which use auxiliary data structures to manage the order of traversal.
                - Network Traversal: Moving between interconnected nodes in a graph. The key here is that a node can have multiple neighbors without a strict parent-child relationship. Algorithms like Breadth-First Search (BFS) and Depth-First Search (DFS) are strategies that use a queue or stack (auxiliary data structures) to manage the exploration order, ensuring all nodes are visited even in the presence of cycles.
    
    b. Querying 🔎
        The act of asking a question about the data and getting an answer, often a boolean or a specific value.
        
        - Examples: contains(element), isEmpty(), size(), min(), max(), elementAt(index), subset(start:finish). These are operations that inspect the data without changing it.
    
    c. Computation ⚙️
        The process of deriving a new value or a new data structure from the existing data. This is about transformation.
        
        Examples: sum(array), average(array), merge(list1, list2), sort(array). Sorting, in this context, is a computation because it transforms an unsorted array into a new, sorted one.

3. Strategies for implementing querying and computation
    a. Stored properties
        This strategy leverages the data structure's known pre-defined properties to perform a query.

       Example: The size of an array, the head of a linked list, the "next" pointer of a linked list node, etc. Also getting the pointer for a particular index of the array using pointer arithmetic could be an example (because we know the array's size, and we know the index of the element we want, and the size of each individual element slot, so we can calculate the pointer of the element we want to fetch).
   
    b. Precomputation ✨
        The strategy of navigating through your data structure in an initial pass to make a new, different, and optimized ADT that you will then use for further processing.

        Example: Creating a hash table from a list of keys to enable near-constant-time queries. Another example is building a prefix sum array to allow for constant-time range sum queries. The act of creating the new data structure is the precomputation.
        
    c. Iterative Refinement 🔬
        This is a problem-solving strategy where you repeatedly apply computations on small portions of your dataset to narrow down a solution. It only operates on the ADT in question.
        
        Example: Binary Search. You repeatedly query the middle element, and based on the result, you compute a new search space (low or high index), and then navigate to that new space. This process continues until a solution is found or the search space is exhausted. Even Linear Search is an example because when you're iteration through individual elements in the array, you're constantly evaluating and storing the intermediate result to find the value you want.

## The Gang of 16 Expressed Through This Framework

That's a powerful way to apply your mental model. By mapping the 16 common interview topics to your framework, you can see how each topic is not just an isolated concept but a specific application of your fundamental operations and strategies.

Here is a breakdown of the 16 common data structures and algorithms, categorized according to this mental model.

1. Abstract Data Types

Arrays, Strings, and Linked Lists: These are your foundational data models. Their primary operations are Linear Navigation (single-pointer, multi-pointer) and Querying (e.g., elementAt(index), isEmpty()).

Stacks and Queues: These are abstract data types with specific constraints on access. Their operations (push, pop, enqueue, dequeue) are a form of limited Linear Navigation.

Hash Maps and Hash Sets: These use Precomputation (hashing) to enable extremely fast Querying (contains, get) and Computation (insert, remove).

2. Algorithmic Strategies
These topics are higher-level strategies that use a combination of your fundamental operations to solve problems.

Trees and Graphs: These topics are the primary domain of Non-Linear Navigation (hierarchical and network traversal). Algorithms like DFS and BFS are the strategies that implement this navigation.

Sorting Algorithms (e.g., Merge Sort, Quick Sort): These are examples of Computation. They take an unsorted data structure and produce a new, sorted one. The underlying process often uses Multi-Pointer Navigation and Precomputation (e.g., Merge Sort splits the list into halves, which is a form of precomputation).

Binary Search: This is a classic example of Iterative Refinement. It uses Multi-Pointer Navigation and Querying to repeatedly reduce the search space by half.

Recursion: This is not a data structure or an algorithm itself, but a technique for implementing algorithms. It often enables Hierarchical Traversal in trees and graphs (e.g., recursive DFS) and Iterative Refinement by breaking down a problem into smaller, similar subproblems.

Heaps: Heaps are a great example of Precomputation. Building a heap from an array is a precomputation step that enables a fast Query (peek) and a specific Computation (extractMin).

Dynamic Programming: This is a powerful form of Precomputation and Iterative Refinement. It involves solving a problem by breaking it down into subproblems and storing the results of these subproblems in an intermediary data structure (often an array or hash map) to avoid re-computation.

Greedy Algorithms: This is a strategy that makes the locally optimal choice at each step with the hope of finding a global optimum. It relies heavily on Querying (e.g., finding the minimum or maximum element) and Computation.

Backtracking: This is a strategy that uses a form of Non-Linear Navigation. It explores a search space by trying to build a solution incrementally. If a path leads to a dead end, it "backtracks" to a previous state and tries a different path. This is often implemented with recursion and a stack (a form of Precomputation with an auxiliary data structure).
