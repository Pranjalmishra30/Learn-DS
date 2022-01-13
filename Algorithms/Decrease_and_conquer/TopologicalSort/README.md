# Topological Sort  

Topological sorting is a linear ordering of vertices of a graph such that for every directed edge u v, 
vertex u comes before v in the ordering. Topological Sorting for a graph is only possible if the graph is a [DAG](https://en.wikipedia.org/wiki/Directed_acyclic_graph) (Directed Acyclic Graph).  
There can be more than one topological sorting for a graph.  

There are 2 main methods of getting the topological sorting of a graph:  
1. DFS method  
2. Source Removal method (Kahn's algorithm)  


This problem can be solved using the adjacency matrix or adjacency list.
Let V = Num of vertices & E = Num of edges.

Time Complexity:  
Adj Mat:  O (V<sup>2</sup>)  
Adj List: O (V+E)
