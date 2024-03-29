# Heap:

## Binary Heap:

- It is an array based data structure
- Viewed as a nearly complete binary tree
### BINARY TREE: 
- #### Defined recursively, a structure defined on FINITE set of nodes 
- #### Nodes must be one of the two
  1. #### Has no nodes(empty or null tree)
  2. #### Has exactly 3 disjoint nodes - root, left and right node.
  
## Definitions:

1. **Depth** (heighest 0, on each segment from root, +1)
2. **Level** 
3. **Height** (node to leaf)

## Attributes of Array A:

1. A.length
2. A.heapsize

> A.heapsize >= A.length


Left child at index i : 2*i+1
Right child at index o : 2*i +2
Parent:  floor(i/2)

## Types of heaps: max and min

### Max heap:  has max element at root

>A[PARENT(i)] >= A[i];

### Min heap: 

> A[PARENT(i)] <= A[i ] 

### Inputs: A,i

### Process: inplace max-heapifying of from index i;

```c
MAX_HEAPIFY(A,i){

    l = 2*i+1;
    r = 2*i+2;

    largest = max(A[l],A[r],A[i]);

    if largest > A.heapsize()
        return;
    
    if largest != i
        swap ( A[largest], A[i]);
        MAX_HEAPIFY(A,largest)
}  
```

## HEAPSORT: 
$$O(nlogn)$$

#### - To restore the Max-heap property, call Max-heapify(A,1) in the n-1 size   

#### - The heapsort algorithm then repeats this process
for the max-heap of size n-1 down to a heap
 of size 2

```c

HEAPSORT
    BUILDHEAP(A)
    for i=A.length-1 to 1
        exchange A[0] , A[i]
        A.heapsize  --
        MAXHEAPIFY(A,0) 
```

![Alt text](image.png)
![Alt text](image-1.png)
![Alt text](image-2.png)

