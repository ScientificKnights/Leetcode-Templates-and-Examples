vector<int> dijkstra(vector<vector<pair<int,int>>> &graph, int K){  //start from node K
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
