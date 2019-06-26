/*
Given a matrix of M x N elements (M rows, N columns), 
return all elements of the matrix in diagonal order as shown in the below image.

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]
*/

vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    // 00 01 02 03
    // 10 11 12 13
    // 20 21 22 23
    int n=matrix.size();
    vector<int> res;
    if(!n) return res;
    int m=matrix[0].size();
    for(int i=0;i<n+m-1;i++){
        if(i%2){
            for(int j=min(i,m-1);j>=0 && i-j<n;j--){
                res.push_back(matrix[i-j][j]);
            }
        }
        else{
            for(int j=min(n-1,i);j>=0 && i-j<m;j--){
                res.push_back(matrix[j][i-j]);
            }
        }
    }
    return res;
}
