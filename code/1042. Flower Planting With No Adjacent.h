/*
You have N gardens, labelled 1 to N.  In each garden, you want to plant one of 4 types of flowers.
paths[i] = [x, y] describes the existence of a bidirectional path from garden x to garden y.
Also, there is no garden that has more than 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, 
they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)-th garden.  
The flower types are denoted 1, 2, 3, or 4.  It is guaranteed an answer exists.

Input: N = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
Example 2:

Input: N = 4, paths = [[1,2],[3,4]]
Output: [1,2,1,2]
*/

vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
    vector<vector<int>> graph(N,vector<int>());
    for(auto i:paths){
        graph[i[0]-1].push_back(i[1]-1);
        graph[i[1]-1].push_back(i[0]-1);
    }
    vector<int> res(N,0);
    for(int i=0;i<N;i++){
        vector<int> colors(5,0);
        for(auto j: graph[i]){
            colors[res[j]]++;
        }
        for(int color=4;color>=0;color--){
            if(colors[color]==0){
                res[i]=color;
                break;
            }
        }
    }
    return res;
}
