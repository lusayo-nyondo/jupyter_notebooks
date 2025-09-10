# Algorithmic Techniques

This is the mental model for algorithmic techniques. This taxonomy is not a set of mutually exclusive boxes but rather a tiered system of abstraction for intuitive understanding. Let's get into algorithmic techniques.

An algorithm is an ordered set of fundamental operations orchestrated by high-level strategies to produce a new value or state.

## 1. Fundamental Operations
These are the basic, atomic actions you perform on data. Think of them as the verbs of algorithms. hey fall into three major categories: Navigation, Querying, and Computation. Let's get into a bit more detail:

### a. Navigation
The process of traversing a data structure to visit its elements. This is about movement and access.

#### i. Linear Navigation
Moving sequentially through elements.

##### 1. Single-Pointer
Using a single index or reference to move one element at a time (e.g., for loop on an array).

##### 2. Multi-Pointer
Using two or more indices or references to move through the data simultaneously. A classic example of this is the two-pointer technique used in arrays to examine them from opposite directions for a specific condition. Another example is the use of fast and slow pointers in a linked list to detect a cycle or find the middle element. Other examples include low and high indices in a binary search.

#### ii. Non-Linear Navigation.
Moving through hierarchical or networked structures.

##### 1. Hierarchical Traversal
Moving between a parent and its children (e.g., traversing a tree). This is the underlying principle for algorithms like Depth-First Search (DFS) and Breadth-First Search (BFS), which use auxiliary data structures to manage the order of traversal.

##### 2. Network Traversal
Moving between interconnected nodes in a graph. The key here is that a node can have multiple neighbors without a strict parent-child relationship.

    Examples: Algorithms like Breadth-First Search (BFS) and Depth-First Search (DFS) are strategies that use a queue or stack (auxiliary data structures) to manage the exploration order, ensuring all nodes are visited even in the presence of cycles.

### b. Querying 🔎
The act of asking a question about the data and getting an answer about the structure of the ADT itself, often a boolean or a specific value.

There are two types of queries:

#### i. Direct Queries (Stored Properties)
These are queries that rely on a pre-existing property of the data structure. You don't need to traverse or compute anything to get the answer; you just "look it up." This is your most efficient type of query.

Examples: Getting the size of an array, the head of a linked list, or the value at a specific index in a hash map.

#### ii. Computed Queries
These are queries that require some form of navigation or computation to get an answer. The result isn't stored, so it must be calculated on demand. A lot of optimization problems fall squarely within implementing these operations.

Examples: contains(element) on an unsorted array (requires navigation), min() or max() on a linked list (requires navigation), or checking if a number is prime (requires computation).

### c. Computation ⚙️
The process of deriving a new value or a new data structure from the existing data. We can break this down based on how the computation's logic is determined.

#### i. Primitive Computation
This is the most foundational form of computation. It uses the computer's circuitry to perform basic mathematical operations and logical comparisons. All other forms of computation are built on these primitives. From the perspective of a programmer, it's things the computer just knows how to do, it's low level, and we don't question it.

    Examples: Arithmetic operations (+, -, *, /), logical operations (AND, OR, NOT), and comparisons (=, <, >): i.e. 1 + 1 = 2, True AND False = False, etc.

#### ii. Algorithmic Computation
This is a computation technique where we as programmers define a fixed, predetermined set of steps to produce a result. The logic is straightforward and doesn't involve a complex decision-making process at each step. Note that algorithmic computations can also contain heuristics (spot-decisions for attempting to achieve the best outcome).

Examples: sum(array), average(array), merge(list1, list2). The instructions are clear and the same every time.

#### iii. Heuristic Computation
This is a computation technique that involves a navigating a data structure and executing some decision-making process at each step to determine whether or not to change the result of the computation. The algorithm doesn't just follow a fixed script and gives a deterministic answer; it makes a choice based on a specific rule or heuristic. General subcategories of this include:

##### 1. Greedy algorithms.

This is a type of heuristic computation that, at each step, makes the choice that looks best at the moment, without considering the global outcome. A good example is Dijkstra's algorithm for finding the shortest path; at each step, the algorithm's heuristic is to choose the unvisited node with the smallest known distance from the starting node. This is a locally optimal choice that is assumed to lead to the overall shortest path. Another example is the sum of consecutive positive differences solution to determine the maximum possible profit in the buy-low sell-high problem.

##### 2. Simulated Annealing 🌡️
This heuristic is inspired by the metallurgical process of annealing, where a metal is heated and slowly cooled to reduce defects.

How it Works: The algorithm starts with a random solution and iteratively makes small, random changes. It always accepts changes that improve the solution. However, it also accepts changes that worsen the solution with a certain probability, which decreases over time (like the cooling process). This "worse-case" acceptance allows the algorithm to escape local optima and explore a wider range of possible solutions.

##### 3. Genetic Algorithms 🌱
This heuristic is inspired by the process of natural selection and evolution.

How it Works: The algorithm maintains a "population" of potential solutions. In each generation, it selects the best-performing solutions, which then "reproduce" (combine) and "mutate" (randomly change) to create new, diverse solutions for the next generation. This process continues until a satisfactory solution is found.

## 2. Optimization Techniques

### a. Precomputation
The strategy of navigating through your data structure in an initial pass to make a new, different, and optimized ADT that you will then use for further processing.

    Example: Creating a hash table from a list of keys to enable near-constant-time queries. Another example is building a prefix sum array to allow for constant-time range sum queries. The act of creating the new data structure is the precomputation. Intervals also fall within this category. The intervals problem is a class of problems often solved by sorting the intervals (a form of precomputation) and then iterating through them to merge or find overlaps.
    
### b. Iterative Refinement
This is a problem-solving strategy where you repeatedly apply queries and computations on small portions of your dataset to narrow down a solution. It only operates on the ADT in question and uses some data structure to store intermediate results. It falls into two major implementation categories:

#### i. Iterative Method (Looping)
This is where you use a standard loop to repeatedly refine the solution. Intermediate results or the state of the algorithm are stored explicitly by you in standard variables or data structures like arrays, queues, or hash maps. This approach gives you full control over the state management.

    Example: A Binary Search implemented with a while loop. The intermediate results are just the low and high variables, which you explicitly update in each iteration. Another example is a sliding window where the intermediate results are stored in a simple primitive variable.

#### ii. Recursive Method
This technique solves a problem by breaking it down into smaller, similar subproblems. Instead of using a loop, it relies on repeated function calls to manage the state. The intermediate results for each function call are automatically stored on the call stack, a stack-based data structure that is managed by the system.
        
    Example: A recursive implementation of Binary Search or a Depth-First Search (DFS) traversal. Each function call pushes a new frame onto the call stack, effectively caching the state of that particular subproblem.

## The 16 Common Interview Questions Explained Using This Mental Model

Now that we've gotten this far, we can try to apply this mental model to think about the 16 categories of common data structures and algorithms questions in interviews.

### Arrays, Strings, and Linked Lists

These are your foundational data models. Their primary operations are Linear Navigation (single-pointer, multi-pointer) and Querying (e.g., elementAt(index), isEmpty()).

### Stacks and Queues

These are abstract data types with specific constraints on access. Their operations (push, pop, enqueue, dequeue) are a form of limited Linear Navigation.

### Hash Maps and Hash Sets

These use Precomputation (hashing) to enable extremely fast Querying (contains, get) and Computation (insert, remove).

### Trees and Graphs

These are the ADTs that are the primary subject of Non-Linear Navigation (hierarchical and network traversal). Algorithms like DFS and BFS are the strategies that implement this navigation.

### Sorting Algorithms (e.g., Merge Sort, Quick Sort)

These are examples of Computation. They take an unsorted data structure and produce a new, sorted one. The underlying process often uses Multi-Pointer Navigation and Precomputation (e.g., Merge Sort splits the list into halves, which is a form of precomputation).

### Binary Search

This is a classic example of Iterative Refinement. It uses Multi-Pointer Navigation and Querying to repeatedly reduce the search space by half.

### Recursion

This is a special programming technique for implementing algorithmic strategies like Iterative Refinement and Non-Linear Navigation. It enables a solution by breaking a problem down into smaller, similar subproblems.

Instead of explicitly managing state with a loop, recursion relies on the call stack, a system-managed stack-based data structure, to implicitly cache intermediate results.

#### i. Application of Recursion in Iterative Refinement
Recursion is a method for implementing the Iterative Refinement strategy. It solves a problem by repeatedly applying a function to smaller portions of the dataset.
    
    Example: A recursive Binary Search is an example of iterative refinement. The search space is continually narrowed, and the state of each subproblem (the low and high indices) is implicitly stored on the call stack.

#### ii. Application of Recursion in Non-Linear Navigation
Recursion is a natural and common way to implement Non-Linear Navigation on hierarchical data structures.
    
    Example: A recursive Depth-First Search (DFS) uses recursion to traverse a tree or graph. The call stack manages the path and allows the algorithm to backtrack to previous nodes, which is the core of DFS.

### Heaps

Heaps are a great example of Precomputation. Building a heap from an array is a precomputation step that enables a fast Query (peek) and a specific Computation (extractMin).

### Prefix Sums and Intervals

Prefix Sums are a perfect example of a Precomputation technique to build an intermediate array for future queries. Intervals are also a good example of precomputation that uses a combination of sorting (another precomputation) and multi-pointer navigation techniques.

### Two-Pointer and Fast-and-Slow Pointer Techniques
These are classic examples of multi-pointer navigation for linear data structures. Both techniques use two or more indices or references to traverse the data simultaneously.

#### a. Two-Pointer Technique 🤝
This is a general technique often used on indexed data structures like arrays or strings. The pointers can move in the same direction (e.g., to find a subarray) or opposite directions (e.g., to find a pair of elements that meet a certain condition).

#### b. Fast-and-Slow Pointer Technique 🐇🐢:
This is a specialized variation typically used on pointer-based data structures like linked lists. The pointers move at different speeds (e.g., one moves two steps for every one step of the other). This speed difference allows them to be in different positions relative to each other after the same number of iterations. It's particularly useful for solving problems that don't require knowing the total length of the list, such as detecting a cycle, finding the middle element, or finding the k 
th node from the end.
  
### Sliding Windows
The Sliding Window technique fits neatly into Iterative Refinement because it's a looping method that repeatedly applies computations on a small, moving portion of a dataset.

### Dynamic Programming.

This is a powerful form of Precomputation and Iterative Refinement. It involves solving a problem by breaking it down into subproblems and storing the results of these subproblems in an intermediary data structure (often an array or hash map) to avoid re-computation.

### Greedy Algorithms.

A greedy algorithm is a great example of a Heuristic Computation. It's a strategy that makes a locally optimal choice at each step while navigating a data structure, with the hope of finding a globally optimal solution.

This strategy relies on a combination of fundamental operations:

Querying: It heavily uses querying to evaluate the available options at a given state (e.g., finding the minimum or maximum element, or the cheapest edge).

Computation: It performs a computation to make the optimal choice based on a specific heuristic.

### Backtracking.

This is a strategy that uses a form of Non-Linear Navigation. It explores a search space by trying to build a solution incrementally. If a path leads to a dead end, it "backtracks" to a previous state and tries a different path. This is often implemented with recursion and a stack (a form of Precomputation with an auxiliary data structure).
