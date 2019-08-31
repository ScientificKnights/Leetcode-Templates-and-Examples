/*
Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

Input:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]

Output:

     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
*/

vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n=A.size(),k=A[0].size(),m=B[0].size();
    vector<vector<int>> res(n,vector<int>(m,0));
    unordered_map<int,vector<pair<int,int>>> mA,mB;
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++){
            mA[i].push_back({j,A[i][j]});
        }
    for(int i=0;i<k;i++)
        for(int j=0;j<m;j++){
            mB[i].push_back({j,B[i][j]});
        }

    // matrix A 第i列的乘以 matrix B 所有第i列的数字，加到对应位置
    for(int i=0;i<n;i++){
        for(auto pairA: mA[i]){
            for(auto pairB: mB[pairA.first])
                res[i][pairB.first]+=pairA.second*pairB.second;
        }
    }
    return res;
}
