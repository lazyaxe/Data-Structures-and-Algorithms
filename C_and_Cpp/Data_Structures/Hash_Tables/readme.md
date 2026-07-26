# **Hash Table in C**

## **What is a Hash Table?**
* A hash table is simply a non-linear data stucture used to store data in key-value pairs with help of a `'hash' function`
* Hash tables/Hash maps and dictionary are used interchangeably in Python and Software development but as Data Structures, these are two different things
* A dictionary is an abstract datatype which is also available in Python. It is available as JSON in JavaScript.
* The Python implementation of dictionary supports all of the basic operations and features of a dictionary.
* A hash table is kind of a subset of dictionary where the key in key-value pair is unique.
* The key is inputed with a 'hash' function, a hash function simply outputs an encoded value.
* The biggest advantage of hash tables is that the `average search time` for the value is `constant O(1)` which is constant and the `worst case`is `O(n)` where there are many hash collisons and the table is effectiively just a linked list due to separate chaining or a list due to closed hashing.

___
### **What is a Hash Function?**
* The input key could be virtually anything from a number, string/text, image etc... 
* But often, due to simplicity in the implementation of a hash function, **similar inputs or sometimes even different input keys get the same hash value as an output. This causes hash collision/conflict.**
* A hash function should be able to:
        1. Ensure randomness in output(to reduce hash collisons and clustering)
        2. Ensure there are no hash collisons.
        3. Ensure easy computation
   * To resolve hash collisions, there are mainly two ways:
       1. separate chaining(using a linked list)
       2. closed hashing(probing)
   * The most preffered approach to deal with collisons is separate chaining.

### **Hash Collision Resosultion Techniques:**
### 1. Separate chaining | Open hashing: 
* In separate chaining when a collision occurs we simply maintain a linked list from the hash index.
* We do not put the value at the end of the linked list but at the start of the linked list because updating the head of the linked list takes constant time, O(1).
* However, in some cases the cost to traverse a linked list isn't that
high so we _can_ insert the collison causing values at the end of the linked list.

![image](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2015/07/hashChaining1.png)

* The worst case now is to finding a value might be at O(n) if the hash function is bad enough.
* However, we can still improve our search time by maintaing a tree(a balanced binary search tree or b tree) instead of single linked list for O(log n).

### 2. Closed hashing:
* Closed hashing is an alternative technique where instead of introducing a linked list or tree to attach to the collision value, we just put the value some place that is vacant.
* There are many ways to do this:
    a. Linear Probing: Linear probing is when we check the empty places for the collision one-by-one starting from the collison hash.
    * This reduces the chances of missing a empty place, but can lead to clustering i.e. too many collided values near to each other.

    b. Quadratic probing: Quadractic probing is another probing technique. Where we look at the increase the index + n ^ 2. Where i = 0 to n
    * For example, an hash collision occured at index 12. Now we'll look at 
12 + 1 ^ 2 = 13, if it's occupied. Then we'll look at 12 + 2 ^ 2 = 16. Then 12 + 3 ^ 2 = 18.

    * So the index value grows quadratically.
    * The good things is that we have reduced the clustering caused by linear probing. 
    * The bad thing is that we might miss the empty spots.

    c. Double Hashing:
    * In double hashing we use two hash functions instead of a single one.
    * The second hash function is only used when there is a hash collison.
    * If in the worst case where both hash functions result in collisions, we can switch to Open Hashing or Closed Hashing as the plan B.

    ![image](https://media.geeksforgeeks.org/wp-content/uploads/20241220122807516193/4_1.webp)
