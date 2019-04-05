/*
Given an undirected graph, return true if and only if it is bipartite.
Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that 
every edge in the graph has one node in A and another node in B.
The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  
Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, 
and it doesn't contain any element twice.

Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.

Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
0----1
| \  |
|  \ |
3----2
*/

bool isBipartite(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int> visited(n,0);
    queue<int> q;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            int level=1;
            visited[i]=1;
            q.push(i);
            while(!q.empty()){
                int len=q.size();
                for(int i=0;i<len;i++){
                    int cur=q.front();
                    q.pop();
                    for(auto i: graph[cur]){
                        if(!visited[i]){
                            visited[i]=level+1;
                            q.push(i);
                        }
                        else if((visited[i]%2)!=(level+1)%2)
                            return false;
                    }
                }
                level++;
            }
        }
    }
    return true;
}
