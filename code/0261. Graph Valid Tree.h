/*
Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), 
write a function to check whether these edges make up a valid tree.

Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true

Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, 
[0,1] is the same as [1,0] and thus will not appear together in edges.
*/

class Solution {
private:
    bool dfs(vector<unordered_set<int>> &graph,vector<int> &visited,int pos){
        if(visited[pos]!=0) return false;
        visited[pos]=1;
        for(auto i:graph[pos]){
            graph[i].erase(pos);
            if(!dfs(graph,visited,i))
                return false;
        }
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> visited(n,0);
        vector<unordered_set<int>> graph(n,unordered_set<int>());
        for(auto i: edges){
            graph[i[0]].insert(i[1]);
            graph[i[1]].insert(i[0]);
        }
        if(!dfs(graph,visited,0)) return false;
        for(auto i: visited)
            if(i==0)
                return false;
        return true;
    }
};
