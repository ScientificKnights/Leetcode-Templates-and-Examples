/*
There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], 
and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
*/

int twoCitySchedCost(vector<vector<int>>& costs) {
    int n=costs.size();
    nth_element(costs.begin(),costs.begin()+n/2,costs.end(),[](vector<int>&a,vector<int>&b){return a[0]-a[1]<b[0]-b[1];});
    int res=0;
    for(int i=0;i<n/2;i++)
        res+=(costs[i][0]+costs[i+n/2][1]);
    return res;
}
