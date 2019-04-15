/*
There are n cities connected by m flights. Each fight starts from city u and arrives at v with a price w.
Now given all the cities and flights, together with starting city src and the destination dst, 
your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        //BFS update所有的edge，level限制，距离长的也可能是答案，没必要priority_queue
        //bellman ford also ok but slower, dijkstra not possible
        queue<pair<int,int>> q;
        vector<vector<pair<int,int>>> graph(n,vector<pair<int,int>>());
        for(auto i:flights)
            graph[i[0]].push_back({i[1],i[2]});
        q.push(make_pair(0,src));
        vector<int> dist(n,INT_MAX);
        int count=0;
        while(!q.empty() && count<=K+1){
            int k=q.size();
            for(int j=0;j<k;j++){
                pair<int,int> cur=q.front();
                q.pop();
                //距离更大的不用考虑，因为count也大
                if(cur.first<dist[cur.second]){
                    dist[cur.second]=cur.first;
                    for(auto next:graph[cur.second])
                        q.push({cur.first+next.second, next.first});
                }
            }
            count++;
        }
        return (dist[dst]==INT_MAX)?-1:dist[dst];
        /*
        dijkstra 用vector而不是priority queue, 不行，因为不能覆盖dist大的，还要考虑次数，下面的例子跑不过
        5
        [[0,1,5],[1,2,5],[0,3,2],[3,1,2],[1,4,1],[4,2,1]]
        0
        2
        2
        vector<vector<int>> graph(n,vector<int>(n,INT_MAX));
        for(auto i:flights)
            graph[i[0]][i[1]]=i[2];
        vector<int> dist(n,INT_MAX);
        vector<int> visited(n,0);
        vector<int> cost(n,0);
        dist=graph[src];
        dist[src]=0;
        visited[src]=1;
        for(int i=0;i<n;i++)
            if(dist[i]!=INT_MAX)
                cost[i]=1;
        cost[src]=0;
        int res=dist[dst];
        
        while(true){
            int next=-1;
            int min_dist=INT_MAX;
            for(int i=0;i<n;i++){
                if(visited[i]==0 && dist[i]<min_dist){
                    next=i;
                }
            }
            //全访问了
            if(next==-1) break;
            visited[next]=1;
            //update dist
            for(int i=0;i<n;i++){
                if(graph[next][i]!=INT_MAX)
                    if(dist[i]>(dist[next]+graph[next][i])){
                        dist[i]=dist[next]+graph[next][i];
                        cost[i]=cost[next]+1;
                    }
                if(cost[dst]<=K+1)
                    res=dist[dst];
            }
        }
        if(res==INT_MAX) return -1;
        return res;
        */
    }
};
