/*
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
Each person may dislike some other people, and they should not go into the same group. 
Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
Return true if and only if it is possible to split everyone into two groups in this way.

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
*/

class Solution {
private:
    bool dfs(vector<vector<int>> &graph,vector<int> &visited,int pos, int signal){
        if( visited[pos]==0){
            if(signal==0) signal=1;
            visited[pos]=signal;
            for(auto i: graph[pos])
                if(!dfs(graph,visited,i,-1*signal))
                    return false;
        }
        else if(signal== (-1)* visited[pos]) 
            return false;
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes){
        vector<int> visited(N+1,0);
        vector<vector<int>> graph(N+1, vector<int>());
        for(auto i:dislikes){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        for(int i=1;i<N+1;i++){
            if(!dfs(graph,visited,i,0)) 
                return false;
        }
        return true;
    }
};
