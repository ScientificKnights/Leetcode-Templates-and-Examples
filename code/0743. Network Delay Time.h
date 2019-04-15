/*
There are N network nodes, labelled 1 to N.
Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, 
v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? 
If it is impossible, return -1.
*/

class Solution {
private:
    vector<int> dijkstra(vector<vector<pair<int,int>>> &graph, int K){
        int n=graph.size();
        vector<int> res(n,INT_MAX);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,K-1});
        
        while(!q.empty()){
            pair<int,int> cur=q.top();
            q.pop();
            if(res[cur.second]==INT_MAX){
                res[cur.second]=cur.first;
                for(auto j:graph[cur.second]){
                    q.push({cur.first+j.second,j.first});
                }
            }
        }
        return res;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int,int>>> graph(N);
        for(auto i:times)
            graph[i[0]-1].push_back({i[1]-1,i[2]});
        vector<int> dist=dijkstra(graph,K);
        int res=INT_MIN;
        for(auto i:dist){
            if(i==INT_MAX) return -1;
            res=max(res,i);
        }
        return res;
    }
};
