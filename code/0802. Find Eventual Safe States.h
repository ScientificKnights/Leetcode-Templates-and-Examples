/*
In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.  
If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.

Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node. 
More specifically, there exists a natural number K so that for any choice of where to walk, 
we must have stopped at a terminal node in less than K steps.

Which nodes are eventually safe?  Return them as an array in sorted order.

The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.  
The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.

Example:
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Here is a diagram of the above graph.
*/

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    //reverse topological sort
    int n=graph.size();
    vector<vector<int>> reversed(n,vector<int>());
    vector<int> indegree(n,0);
    queue<int> q;
    for(int i=0;i<n;i++){
        for(auto j:graph[i]){
            reversed[j].push_back(i);
        }
        indegree[i]=graph[i].size();
        if(!graph[i].size()) q.push(i);
    }
    vector<int> res;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        res.push_back(cur);
        for(auto i: reversed[cur]){
            indegree[i]--;
            if(!indegree[i]) q.push(i);
        }
    }
    sort(res.begin(),res.end());
    return res;
}
