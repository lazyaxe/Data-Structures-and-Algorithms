# Linked List

### What is a linked list?
* Linked is a linear data structure primarily used to store homogenous type of objects.
* Linked lists serve as an alternative to 1D array for storage of data.
* Fundamentally, linked lists are a linear collection of nodes with one node having information about the next node.
* We always start from the head/root node and end at tail node
<br>
[Root]-->[Second_Node]--> ... -->[Tail_Node]
<br>

#### What are nodes?
* Nodes are basic unit of storage in a linked list.
* Each node has the address of the next in line
* In a simple linked list, a node does not address of the node before it .i.e previous node.

### Advantages Of Linked List Over Arrays:
1. Modifiable size:
    * Since linked only consists of nodes, the computation required to add/delete a node is much lesser than modifying an array's size.

2. No wastage of memory:
    * If an array is sparse the memory space allocated to the array is wasted as it could be used somewhere else.
    * Whereas in linked list the number of nodes are exactly the number of items stored.
3. Variations: 
    * There are many variations of the linked list such as:
    1. Doubly Linked List
    2. Circular Linked List

4. Linked List is used as a helper data structure in other data structures such as Stack, Queue, Trees, Graphs, Hash Tables etc...

### Disadvantages Of Linked List Over Arrays:
1. Slower Search Time O(n):
    * As in linked list we always start from the head/root node
    so in the worst case we'll need to search the entire list.
    * Whereas in an array, search time is constant
2. No change in Insert and Delete time:
    * Continuing  the first point, there's no change in search, insert and delete time as in the worst case we would need to insert at or delete the last element
3. Increased Complexity

### TL:DR;
* Use Linked Lists if the application has frequent insert and delete data operations and storage cannot be wasted.
* Use Arrays, if the appliccation has frequent read(index based) operations and modification(index-based) operations.