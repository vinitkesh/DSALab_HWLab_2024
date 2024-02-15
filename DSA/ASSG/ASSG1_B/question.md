QUESTIONS
1. Given an inorder and a preorder traversal of a binary tree, construct the unique binary tree T
corresponding to the traversals given.
The binary tree contains non-negative integers as data to be sorted.
The program should support the following functions:
(a) main(): Repeatedly reads an input character from the menu list through the terminal and
executes menu driven operations accordingly.
(b) PostOrder(T): Prints the post order traversal of the binary tree T
(c) ZIG ZAG(T): Prints the ZIGZAG traversal (Definition is given below) of the binary tree T
(d) Level Max(T): Prints maximum element at each level of the binary tree T.
(e) Diameter(T): Prints the diameter of the binary tree T
(f) Left Leaf Sum(T): Prints the sum of the values of left leaf nodes.
Definitions:
Depth of a node: Length(no of edges) of the unique simple path from the root to the node
Level of a tree: All the nodes at the same depth form a level of the tree. Root is at level 0 and the
nodes at depth 1 are at level 1, nodes at depth 2 are at level 2.
ZIG-ZAG Traversal of a Binary Tree: It is a level order traversal in which if the level no is even,
nodes will be printed from left to right and if the level no is odd, nodes will be printed from right
to left. Please note that level no starts from 0.
DIAMETER of tree :The diameter/width of a tree is defined as the number of nodes on the longest
simple path between two end nodes.
Left Leaf Node: A leaf node which is present as a left child to its parent node.
Input Format:
• The first line is an integer n ∈ [1, 106
] indicating the number of nodes in the tree.
• Second line of the input contains a space separated integer sequence of “n” numbers representing INORDER traversal of the tree T with key values ∈ [1, 106
]
• Third line of the input contains a space separated integer sequence of “n” numbers representing
PREORDER traversal of the tree T with key values ∈ [1, 106
]
• Next Each line contains a character [‘p’,’z’,’m’,’d’,’s’, ’e’].
– Character ‘p’ call - Postorder(T) - is to print the post order traversal of a tree.
– Character ‘z’ call - ZIG ZAG(T) - is to print the zig-zag traversal of the tree.
– Character ‘m’call - Level Max(T) - is to print max elements at each level.
– Character ‘d’ call - Diameter(T) - is to print the diameter of a binary tree.
– Character ‘s’ call - Left Leaf Sum(T) - is to print the sum of all left leaf nodes.
– Input ‘e’ terminates the execution of the program.
Output Format:
• Lines contains appropriate output sequence of integer or an integer output
2
Sample Input 1:
7
4 2 5 1 6 3 7
1 2 4 5 3 6 7
p
z
m
d
s
e
Sample Output 1:
4 5 2 6 7 3 1
1 3 2 4 5 6 7
1 3 7
5
10
Sample Input 2:
4
4 2 5 1
1 2 4 5
z
p
s
d
e
Sample Output 2:
1 2 4 5
4 5 2 1
4
3