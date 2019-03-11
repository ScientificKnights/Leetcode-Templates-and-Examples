/*
In this problem, a tree is an undirected graph that is connected and has no cycles.
The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), 
with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, 
that represents an undirected edge connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. 
If there are multiple answers, return the answer that occurs last in the given 2D-array. 
The answer edge [u, v] should be in the same format, with u < v.

Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
    |   |
    4 - 3
*/

class Unionfind{
private:
    vector<int> root;
public:
    //constructor
    Unionfind(int n){
        root=vector<int>(n+1,0);
        for(int i=0;i<n;i++)
            root[i]=i;
    }
    //Union
    bool Union(int u,int v){
        int root_u=findroot(u),root_v=findroot(v);
        if(root_u==root_v) return false;
        root[root_u]=root_v;
        return true;
    }
    //find root
    int findroot(int u){
        if(u!=root[u])
            root[u]=findroot(root[u]);      //path compression
        return root[u];
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        Unionfind uf(edges.size());
        for(auto i:edges){
            if(!uf.Union(i[0],i[1]))
                return i;
        }
        return {};
    }
};
