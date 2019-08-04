/*
There are N cities numbered from 1 to N.
You are given connections, where each connections[i] = [city1, city2, cost] represents the cost to connect city1 and city2 together. 
(A connection is bidirectional: connecting city1 and city2 is the same as connecting city2 and city1.)

Return the minimum cost so that for every pair of cities, there exists a path of connections (possibly of length 1) 
that connects those two cities together.  The cost is the sum of the connection costs used. If the task is impossible, return -1.

Input: N = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
Output: 6

Input: N = 4, connections = [[1,2,3],[3,4,4]]
Output: -1

Note:

1 <= N <= 10000
1 <= connections.length <= 10000
1 <= connections[i][0], connections[i][1] <= N
0 <= connections[i][2] <= 10^5
connections[i][0] != connections[i][1]
*/

class UnionFind{
private:
    vector<int> root;
    int count;
public:
    UnionFind(int n){
        root=vector<int>(n,0);
        for(int i=0;i<n;i++)
            root[i]=i;
        count=n;
    }
    int findroot(int i){
        if(root[i]!=i)
            root[i]=findroot(root[i]);
        return root[i];
    }
    bool merge(int i,int j){
        int ri=findroot(i),rj=findroot(j);
        if(ri==rj) return false;
        else{
            count--;
            root[ri]=rj;
        }
        return true;
    }
    int getcount(){
        return count;
    }
};

class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        UnionFind uf(N);
        sort(connections.begin(),connections.end(),[](vector<int> l,vector<int>r){
            return l[2]<r[2];
        });
        int res=0;
        for(auto i:connections){
            if(uf.merge(i[0]-1,i[1]-1)) {
                cout<<i[2];
                res+=i[2];
            }
        }
        return (uf.getcount()==1)?res:-1;
    }
};
/*
class Solution {
public:
    vector<int> dijkstra(vector<vector<pair<int,int>>> &graph, int &r){
        int n=graph.size();
        vector<int> res(n,INT_MAX);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,0});

        while(!q.empty()){
            pair<int,int> cur=q.top();
            q.pop();
            if(res[cur.second]==INT_MAX){
                res[cur.second]=cur.first;
                for(auto j:graph[cur.second]){
                    q.push({j.second,j.first});
                }
                r+=cur.first;
            }
        }
        return res;
    }
    
    int minimumCost(int N, vector<vector<int>>& times) {
        vector<vector<pair<int,int>>> graph(N);
        for(auto i:times){
            graph[i[0]-1].push_back({i[1]-1,i[2]});
            graph[i[1]-1].push_back({i[0]-1,i[2]});
        }
        int res=0;
        vector<int> d=dijkstra(graph,res);
        //int dd=INT_MIN;
        for(auto i:d){
            if(i==INT_MAX) return -1;
        }
        return res;
    }
};
*/
