/*
We have a list of bus routes. Each routes[i] is a bus route that the i-th bus repeats forever. 
For example if routes[0] = [1, 5, 7], this means that the first bus (0-th indexed) travels 
in the sequence 1->5->7->1->5->7->1->... forever.

We start at bus stop S (initially not on a bus), and we want to go to bus stop T. 
Travelling by buses only, what is the least number of buses we must take to reach our destination? Return -1 if it is not possible.

Example:
Input: 
routes = [[1, 2, 7], [3, 6, 7]]
S = 1
T = 6
Output: 2
Explanation: 
The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
*/
int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
    if(S==T) return 0;
    unordered_map<int, set<int>> m;
    for(int i=0;i<routes.size();i++)
        for(auto j:routes[i])
            m[j].insert(i);
    queue<int> q;
    vector<int> visited_route(routes.size(),0);
    for(auto i: m[S])
        q.push(i);
    int level=1;
    while(!q.empty()){
        int k=q.size();
        for(int i=0;i<k;i++){
            int cur=q.front();
            q.pop();
            visited_route[cur]=1;
            for(auto stop:routes[cur]){
                if(stop==T) return level;
                for(auto j:m[stop]){
                    if(!visited_route[j])
                        q.push(j);
                }
            }
        }
        level++;
    }
    return -1;
}
