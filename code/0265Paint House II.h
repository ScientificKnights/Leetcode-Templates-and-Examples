/*
There are a row of n houses, each house can be painted with one of the k colors. 
The cost of painting each house with a certain color is different. 
You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. 
For example, costs[0][0] is the cost of painting house 0 with color 0; 
costs[1][2] is the cost of painting house 1 with color 2, and so on... 
Find the minimum cost to paint all houses.
*/

int minCostII(vector<vector<int>>& costs) {
    int n=costs.size();
    if(n==0) return 0;
    int k=costs[0].size();
    if(k==1) return costs[0][0];
    //找到最小的两个，如果上一行是最小的，用第二小的
    //O(nK)
    int min1=INT_MAX,min2=INT_MAX;
    for(auto i:costs[0]){
        if(i<min1){
            min2=min1;
            min1=i;
        }
        else if(i<min2)
            min2=i;
    }

    for(int i=1;i<n;i++){
        int new_min1=INT_MAX,new_min2=INT_MAX;
        for(int j=0;j<k;j++){
            costs[i][j]+=(costs[i-1][j]==min1)?min2:min1;
            if(costs[i][j]<new_min1){
                new_min2=new_min1;
                new_min1=costs[i][j];
            }
            else if(costs[i][j]<new_min2)
                new_min2=costs[i][j];
        }
        min1=new_min1;min2=new_min2;
    }
    return min1;
}
