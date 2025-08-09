# Data Structures

## What are data structures?

To properly define a data structure, we need to first talk about where they live when you're using them in your programs and what we do with them.

As you can imagine, generally, data structures exist within RAM. They're basically a collection of interelated bytes and pointers that are being stored there for your programs to use. These bytes can either be physically right next to each other in a sequence, or they can be in completely distant regions of your RAM. All that matters is that they are modeled in a way that allows us to group related bytes together. The way that you choose to do that is what we're going to refer to as your Storage Model.

Let's put a pin in that to talk about what we do with these bytes. Even when you've stored a collection of interlated bytes and pointers in your RAM, your RAM doesn't know that the bytes it contains mean something to you. They're just electric charges that were put there. It's up you, the programmer, and your program, to define a logical contract for how those bytes should be treated to do anything meaningful. That's we call an Abstract Data Type.

Having a grasp of these two concepts, a Data Structure is essentially a logical unit of data that is defined by both the Storage Model you've used to represent it in memory, and its Abstract Data Type (ADT) that tells you how to interact with them. Essentially, the foundational storage model describes how data is physically stored and accessed in memory, while the ADT defines its logical behavior and constraints.

Let's get into a bit more detail.

## Foundational Storage Models: Indexes and Pointers
The two fundamental ways to store data are through indexes and pointers. Each has its own set of strengths and limitations.

## Indexes
Indexes refer to a data storage model where related elements of the same type are stored in a contiguous block of memory. This fixed, ordered arrangement makes it possible to access any given element within a constant time.

How does this black magic work? Let's discuss it in the next section.

### Accessing Elements in an Index

The key to this is that Indexes are predefined to have a fixed size, and each element in the index has to be of the same type, and therefore also has the same size. Locations in your RAM are represented using numbers.

The RAM itself is one big index. It contains millions of slots, each of a fixed size, called a "byte". You can reference a byte using a numerical index. For example, you can ask the RAM to put something in byte number 34, or to retrieve something that's stored in byte number 1037. You can also work with groups of bytes. So you can essentially ask your RAM to put something in byte numbers 500-536, or to retrieve something stored in another range of bytes absolutely anywhere in the RAM.

Having understood that, when you store an Indexed data structure in RAM, you place all of its elements physically next to each other. That means that all the numerical indices of the RAM in between the start of your data, and the end of your data, only contain your data.

Let's say that in your program, you want to define a list of 5 integers that you wanted to store inside RAM. Let's just assume that each integer takes up 4 bytes of RAM, because all similar elements take up the same amount of space.

Here's what that looks like in pseudocode:

    intArray = [1, 2, 3, 4, 5]

Now, your program has to ask your CPU, "Hey. I have a list of 5 integers, each of them are 4 bytes. That's 20 bytes total. So can you find somewhere in RAM to store these 20 bytes for me? I want them right next to each other."

Your CPU says, "Sure. There's an empty table over in index 2000 that has just enough space to fit all of your integer friends."

Now, you store your list of integers at that location. So basically, your integers occupy the memory indices 2000 - 2020.

If you want to get the first integer in your list, you'll find it at index 2000. If you want the second integer, you'll find it at index 2004 (since the first integer occupied 4 bytes, and the elements are all physically next to each other). The third integer is at 2008, and so on and so forth.

Now, let's say, you only have a pointer to the beginning of your array. That is your "intArray" variable typically will only contain the exact index of the beginning of your array. We'll use a "&" symbol after the array variable name to note that we're talking about the exact pointer inside the intArray variable, and not just the data it points to.

Basically, the value inside intArray& = 2000. Because 2000 is the memory index that contains the very first element in your array.

What do you do when you want to find a pointer to the second element in your array?

Well, that's easy. You know that each element is 4 bytes (because integers are 4 bytes by definition), so you just say, the second element is at the location:
    - 2000 + 4 = 2004

To get the third element, you can just also calculate the pointer by saying:
    - 2000 + 2 * 4 = 2000 + 8 = 2008

To get the fourth element, you can just say:
    - 2000 + 3 * 4 = 2000 + 12 = 2012.

Basically, to get a pointer to the nth element of the array, you can just say:
    - startingPointer + (n - 1) * elementSize

where the startingPointer is the Index of the first element, and the n is the size of the array.

To your computer, this is an operation it can do in a constant time. It doesn't matter if this operation resolves to 2000 + (2 * 4) or 2000 + (3 * 4). These operations take the exact same amount of time for your CPU to complete.

That's why we say that accessing elements in an Indexed data structure can be done in constant time. Because this mathematical operation to get a pointer to any given element within the array can also be done in constant time.

Also note that the formula for calculating the element "n" had a coefficient of "n - 1". We can even use this to get the first element of the array. In this case it would be:
    - 2000 + (1 - 1) * 4 = 2000 + (0 * 4) = 2000 + 0 = 2000.

As you can see, the actual coifficient that multiplies against the element size for the first element to get the location of the first element is 0. It is for this reason that when using this index model in computers, the first element is referenced using an index of 0.

Anyway, let's recap so we don't get lost in the weeds. An Indexed Storage Model is a Storage Model that stores interelated elements of fixed size within a contiguous memory block. Combine that with the mathematics we just demonstrated, that's why it provides constant time access to any given element within it.

Now, let's talk about adding and removing items to this Storage Model.

### Adding and Removing Items in an Index Model
I'll be quick to just point out that this model is not efficient for adding and removing items.
The primary cause of this is the same reason why it's great for accessing elements at any random location: it has to be stored in a continuous uninterrupted memory block.

So for example, if there's any bytes that are occupied that come after it, we can't just add more elements to it. There's no space in RAM to do so. It's like making reservation for a table for two, and then bringing two more people along to a two-seat table. The restaurant will have to move you to a four seat table.

To be more accurate, the restaurant will first have to prepare your new table. And then every single one of you will have to move from the small table, to the new one.

This is why we say that insert operations in the Indexed Storage Model are slow. Essentially, any time you want to add a new element to the Index, you need to find a new location in memory where your data can live, and then you have to copy all of your data to that new location.

Sometimes the same logic can apply when you're removing items. If the restaurant is particularly packed, they'll want to make sure everybody only takes the specific number of seats they need. If you reserve a three-person seat then one of you leaves, the restraurant might try to move you to a two-seat table. This will also take time to complete.

That's why the Index Storage Model is not particularly great for inserts and deletes.

That's enough of this model. Let's talk about the other core Storage Model. Fortunately, it's must faster with inserts and deletes, but because of the way it's defined, it's also very slow at accessing random memories like the Indexed Storage Model. Let's dive right in.

## Pointers
Pointers refer to a data storage model where elements are stored in non-contiguous memory locations. Each element, often called a node, contains the data itself plus a reference, or pointer, to the next element in the sequence.

The elements can be scattered all over your computer's RAM. The only thing that connects them is the pointer inside each node, which holds the exact memory address of the next node. The entire structure is held together by a single variable, typically called the "head," which points to the very first node.

### Accessing Elements in a Pointer Model
To get to a specific element in this model, there's no mathematical shortcut. You must begin at the head and sequentially follow each pointer until you arrive at your destination. This is like a scavenger hunt where each clue tells you where to find the next clue. You can't skip ahead; you must follow the trail.

For example, to find the third element in a linked list, you'd have to start at the head, follow its pointer to the second element, and then follow that element's pointer to the third. Because you must visit each element on the way to your destination, finding an item in this model takes a variable amount of time that depends on the item's position. The further down the list an element is, the longer it takes to find.

### Adding and Removing Items in a Pointer Model
Unlike the index model, this model is fantastic for adding and removing items. Since the elements don't need to be in a single, contiguous block, you can place a new element anywhere in RAM.

To insert a new element, you simply create the new node, update the pointer of the preceding node to point to the new node, and then set the new node's pointer to point to the node that comes after it. It's like cutting a rope and tying in a new piece—you only need to change a couple of knots. This makes adding an item a very fast operation.

Removing an item is just as simple. You find the element you want to remove and then update the pointer of the preceding element to point to the element that comes after the one you're deleting. The deleted element is no longer part of the sequence, and the rest of the list remains intact.

## Abstract Data Types (ADTs)

Like we said, an Abstract Data Type is essentially the contract that your program has with those bytes that you've stored in your memory. It is completely independent of the actual storage model used. However, an Abstract Data Type, together with a specific storage model or a collection of storage models, is what we refer to as a Data Structure.

### Relationship Between Abstract Data Types and Storage Models
An Abstract Data Type (ADT) is a logical model of a data structure. It's a conceptual blueprint that defines a set of operations and the rules for how data is accessed and manipulated, without specifying the underlying storage model used.

An ADT can be implemented using either an index-based or a pointer-based storage model or even both. For example, Hash Maps use the Pointer storage model for their keys, which then undergo a hash function, to access the underlying Indexed storage model of the values.

Sometimes the actual underlying storage model might feel a little counterintuitive at best glance. For example, Heap is conceptually a tree (a non-linear ADT), but it can be and is often efficiently implemented using a simple array (an index-based storage model) because it has the completeness property.

For the majority of our study of Data Structures, we'll actually be discussing the various case studies for useful Abstract Data Types that are commonly used together with the storage models that make sure they're implemented in an optimal way.

Like we said, Abstract Data Types typically have logical constraints that are used to constrain their behavior and give them logical properties that are useful for our computations. Let's talk about this a little.

### Typical Logical Constraints for Abstract Data Types

ADTs impose various constraints on their data. These constraints determine the structure's behavior and define its public interface. There are several approaches one can take to try to classify the logical rules that typically define Abstract Data Types, however, I'm going to focus on the three types of constraints that I feel are prominent:

#### Access Constraints.
An ADT can limit how you access data. For example, a Stack enforces a Last-In, First-Out (LIFO) access pattern, while a Queue enforces a First-In, First-Out (FIFO) pattern.

#### Ordering Constraints
An ADT can mandate a specific order for its elements. A Heap is a great example, imposing the heap property, which states that for any given node, its value must be greater than or equal to (or less than or equal to) the values of its children. This property dictates the tree-like structure and is crucial for operations like peek() and extract-min/max().

#### Relationship Constraints
An ADT can define specific relationships between its elements. A Tree models a parent-child relationship, and a Graph models a network of interconnected nodes, where the connections can be one-way or two-way.

## Useful Data Structures

After our discussion of the two fundamental Storage Models, and their relationship to Abstract Data Types, we can now start talking about some useful ADTs that are researched and widely used in computer science. This is is by no means exhaustive. ADTs can be formed for many different specialized usecases. It's just a matter of creativity. Here are some of the more well-defined and known ones:

### 1. Linear Data Structures (ADTs with sequential access)
These ADTs organize data in a linear sequence.

#### Static and Dynamic Arrays (1, 2):
These are Index-Based data structures. Static arrays have a fixed size defined at creation, while dynamic arrays can grow or shrink by creating a new, larger array and copying elements over. Their key feature is random access, allowing for constant-time element retrieval using an index.

#### Singly, Doubly, and Circular Linked Lists (3, 4, 5):
These are Pointer-Based data structures. They consist of nodes linked together. Singly linked lists have a single pointer to the next node. Doubly linked lists add a pointer to the previous node for bidirectional traversal. Circular linked lists have the last node's pointer loop back to the first node. Their main advantage is efficient insertion and deletion.

#### Stacks, Queues, and Dequeues (6, 7, 8):
These are Abstract Data Types defined by their access constraints. A Stack is LIFO (Last-In, First-Out). A Queue is FIFO (First-In, First-Out). A Dequeue (Double-Ended Queue) allows for insertions and deletions at both ends. They can be implemented using either an array or a linked list, with the linked list being the more common choice for dynamic resizing.

### 2. Hash-Based ADTs (ADTs for efficient key-value access)
These ADTs use a hash function as a core component of their functionality.

#### Hash Tables and Hash Maps (9, 10):
These ADTs use a Precomputation technique (hashing) to map a key to an index in an underlying array. This allows for near-constant time direct querying for a value. A Hash Table stores keys, while a Hash Map stores key-value pairs.

#### Bloom Filters (11):
A probabilistic data structure that uses multiple hash functions. It's a type of Computed Query that can tell you if an element is definitely not in a set, but cannot definitively say it is in the set (it might return a "false positive"). It is used to save memory.

### 3. Tree-Based ADTs (ADTs with a hierarchical structure)
These ADTs use a non-linear, hierarchical storage model.

#### General Trees, Binary Trees, Binary Search Trees (12, 13, 14):
Trees are the foundational ADT, modeling a parent-child relationship.

##### Binary Trees.
These are a specific type where each node has at most two children.

##### Binary Search Trees (BSTs)
These are Binary Trees that add an ordering constraint where all left children are smaller than the parent, and all right children are larger. This allows for efficient searching using iterative refinement.

#### Self-Balancing Trees (AVL, Red-Black, Splay) (15, 16, 17)
These are specialized BSTs that automatically reorganize themselves on insertion or deletion to prevent the tree from becoming unbalanced. This guarantees that search, insertion, and deletion operations remain efficient.

#### B-Trees (18)
A self-balancing tree designed for disk-based storage. It optimizes for the number of disk accesses by keeping more data in each node, making it ideal for databases and file systems.

#### Tries and Ternary Search Trees (21, 22)
These are specialized trees for storing strings. A Trie (prefix tree) uses prefixes to store keys, making it excellent for prefix-based searching and auto-complete. Ternary Search Trees are a more space-efficient variant.

#### Quadtrees, Octrees, and K-d Trees (35, 36, 37)
These are spatial partitioning trees. A Quadtree recursively divides a 2D space into four quadrants. An Octree does the same for 3D space. K-d Trees generalize this to any number of dimensions. They are used for efficiently querying points in space.

### Treaps (38)
A probabilistic data structure that combines a BST's ordering property with a heap's ordering property to maintain balance with high probability.

### R-Trees (39)
A tree data structure used for spatial access methods, particularly for multi-dimensional data such as geographic coordinates.

## 4. Heap-Based ADTs (ADTs for priority management)
These are specialized tree-based ADTs with specific ordering constraints.

### Heaps (19)
A binary tree-based ADT that satisfies the heap property: a parent's value is always greater than its children (max-heap) or less than its children (min-heap). This allows for fast direct queries for the minimum or maximum element. Heaps are excellent examples of a logical tree structure implemented efficiently with an index-based array.

### Fibonacci Heaps (20)
A more complex heap variant that optimizes for operations like merge and decrease-key, making it particularly useful in graph algorithms like Dijkstra's.

## 5. Graph-Based ADTs (ADTs for modeling networks)
These ADTs are defined by their relationship constraints, modeling complex connections between nodes.

#### Graphs (23-28):
The most general non-linear ADT. A graph consists of nodes (vertices) and connections (edges).

#### Directed Graphs
These are graphs that have one-way edges.

#### Undirected Graphs
These are graphs that have two-way edges.

#### Weighted Graphs
These are graphs that have values associated with their edges.

#### Acyclic Graphs
These are graphs that contain no cycles.

#### Bipartite Graphs are graphs
These are graphs whose nodes can be divided into two disjoint sets.

### Disjoint Set Union (DSU) (29)
An ADT that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets. It uses a tree-like structure to efficiently perform find and union operations.

## 6. Specialized & Advanced ADTs
These ADTs use unique combinations of fundamental operations and optimization strategies.

###  Segment Trees and Fenwick Trees (30, 31)
These are specialized tree structures that use Precomputation to allow for fast computed queries over a range of data (e.g., finding the sum of a subarray in constant time).

### Skip Lists (32)
A probabilistic data structure that uses multiple layers of linked lists to create a hierarchy. This allows for searching in a linked list in a much more efficient manner, a form of iterative refinement.

### Suffix Trees and Suffix Arrays (33, 34)
These are used for efficient string-matching and pattern-finding. A Suffix Tree is a tree-based ADT that stores all suffixes of a string. A Suffix Array is an optimized, array-based alternative.

### Van Emde Boas Trees and Fusion Trees (40, 42)
Highly advanced tree-based ADTs that are typically used for integer-based data and offer highly optimized performance.

### Finger Trees (41)
A functional data structure that allows for fast access at its ends and at a "finger," a pointer to a specific element.

### Persistent Data Structures (43)
These are data structures that preserve their previous versions when they are modified. This is a form of Precomputation that uses additional space to allow for history-based queries.

We'll go over these in more details within our Data Structure case studies and practical exercises.