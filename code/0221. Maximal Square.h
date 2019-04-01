/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/

int maximalSquare(vector<vector<char>>& matrix) {
    //DP 两个row 存数据，不用m*n
    //到这点的最大的square
    int res=0;
    int n=matrix.size();
    if(n==0) return 0;
    int m=matrix[0].size();
    vector<int> prev(m+1,0);
    for(int i=0;i<m;i++){
        if(matrix[0][i]=='1'){
            prev[i+1]=1; res=1;
        }
    }
    for(int i=1;i<n;i++){
        vector<int> curr(m+1,0);
        for(int j=1;j<m+1;j++){
            curr[j]=((matrix[i][j-1]=='1')?(min(min(prev[j],prev[j-1]),curr[j-1])+1):0);
            res=max(res,curr[j]);
        }
        prev=curr;
    }
    return res*res;
}
