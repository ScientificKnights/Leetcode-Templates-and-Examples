/*
Given a matrix, and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: 
for example, if x1 != x1'.

Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4

Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
*/

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int n=matrix.size(),m=matrix[0].size();
    for(int i=0;i<n;i++)
        for(int j=1;j<m;j++)
            matrix[i][j]+=matrix[i][j-1];
    int res=0;
    for(int i=0;i<m;i++)
        for(int j=i;j<m;j++){   //这步必需从m的方向做
            unordered_map<int,int> sum;
            sum[0]=1;
            int cur=0;
            for(int k=0; k<n ;k++){
                cur+= matrix[k][j]-(i?(matrix[k][i-1]):0);
                res+=sum[cur-target];
                sum[cur]++;
            }
        }
    return res;
}
