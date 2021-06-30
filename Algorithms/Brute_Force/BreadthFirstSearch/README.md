# Breadth First Search  

Breadth-first search (BFS) is an algorithm for traversing or searching tree or graph data structures.It starts at a source node and explores all of the adjacent nodes at the present depth and then moving on to the nodes at the next depth level. We can use a Queue to keep a track of the nodes.  

It uses the opposite strategy of DFS, which instead explores the node branch as far as possible before being forced to backtrack and expand other nodes.

BFS can be solved using the adjacency matrix or adjacency list.  
V = Num of vertices & E = Num of edges. 

Time Complexity:
Adj Mat: O( V<sup>2</sup> )  
Adj Lst: O( V+E ) 
