/*
For an undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. 
Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). 
Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges 
(each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] 
and thus will not appear together in edges.

Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3 

Output: [1]

Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5 

Output: [3, 4]

According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
*/

vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(n,vector<int>());
    for(auto i:edges){
        graph[i.first].push_back(i.second);
        graph[i.second].push_back(i.first);
    }
    vector<int> ans;
    vector<int> degree(n);
    for(int i=0;i<n;i++) degree[i]=graph[i].size();
    int total=n;
    while(total>2){
        vector<int> to_delete={};
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                total--;
                to_delete.push_back(i);
                degree[i]=-1;
            }
        }
        for(auto i:to_delete)
            for(auto j:graph[i])
                degree[j]--;
    }
    for(int i=0;i<n;i++)
        if(degree[i]>=0)
            ans.push_back(i);
    return ans;
}
