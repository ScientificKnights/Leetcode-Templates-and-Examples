/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) 
and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
*/

class NumMatrix {
    //dp 储存sums
private:
    int n;
    int m;
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>> matrix) {
        sums=matrix;
        n=matrix.size();
        if(n==0) return;
        m=matrix[0].size();
        for(int i=1;i<n;i++)
            sums[i][0]+=sums[i-1][0];
        for(int i=1;i<m;i++)
            sums[0][i]+=sums[0][i-1];
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
                //dynamic programming
                sums[i][j]+=sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(n==0)
            return 0;
        int sum=sums[row2][col2];
        if(row1!=0)
            sum-=sums[row1-1][col2];
        if(col1!=0)
            sum-=sums[row2][col1-1];
        if(row1!=0 && col1!=0)
            sum+=sums[row1-1][col1-1];
        return sum;
    }
};
