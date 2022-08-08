/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 
to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, 
where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and 
vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.
*/

/*
Example: let n = 4, so we have nodes 0..3
the edges [2,3] and [2,1] are inserted
0 1 2 3
0 1 3 3 insert [2,3] the index 2 now points to 3
0 1 3 1 insert [2,1] the index 2 points to 3 which points to 1, notice array[1] = 1 which indicates a tail
...
As we insert edges these lists grow within the array and we check if the tail of the list source and destination are equal. 

*/

class Solution {
public:
    
    //recursively finds the "tail" of path to connect to another tail through group
    int find(int i, int a[]) { 
        return (a[i] == i) ? i : find(a[i], a); 
    }
    
    //grouping allows us to conserve time and memory by using indexes and their values as links in the graph
    //this is ideal if we only want to see if two nodes are connected
    void group(int i, int j, int a[]) {
        a[find(i, a)] = find(j, a);
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int a[n];
        iota(a, a + n, 0);
        
        for (vector<int> &e: edges) 
            group(e[0], e[1], a);
        
        return find(source, a) == find(destination, a);
    }
};
