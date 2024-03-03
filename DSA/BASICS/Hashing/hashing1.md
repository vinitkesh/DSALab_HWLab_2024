# Hashing I
### Dictionary : Abstract data type( ADT)

### Maintains a set of item, it can : 
#### 1. Insert(item)
#### 1. Delete(item)
#### 1. Search (key)

## Direct-Address Array

>**works well when the universe U of
keys is reasonably small**

|Operation |TC|
|---|-----|
| 1. Insert(item) | O(1) |
| 2. Delete(item) | O(1) |
| 3. Search (key) | O(1) |

> ### Why dont we use this in every situation ?

> because of soo much extra space it takes

> Since we have no idea what bounds a thing can go
---

### Methods:

>#### DIRECT-ADDRESS-SEARCH(T, k)  
>#### return T[k]  

>#### DIRECT-ADDRESS-INSERT(T, x)  
>#### T[key[x]]  ← x  

>#### DIRECT-ADDRESS-DELETE(T, x)  
>#### T[key[x]] ← NIL  

## Linear Probing as the Collision detection method

Insertion:
```
while(hash[i])
```

```c
struct 
```





