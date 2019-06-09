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
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10
*/

class NumMatrix {
    //O(m) memory record sum of colums
private:
    int n;
    vector<vector<int>> colsum;
public:
    NumMatrix(vector<vector<int>> matrix) {
        n=matrix.size(); 
        if(!n) return;
        int m=matrix[0].size();
        
        colsum=matrix;
        for(int i=0;i<m;i++)
            for(int j=1;j<n;j++)
                colsum[j][i]+=colsum[j-1][i];
    }
    
    void update(int row, int col, int val) {
        int increase=val- (colsum[row][col]-(row?colsum[row-1][col]:0));

        for(int i=row;i<n;i++)
            colsum[i][col]+=increase;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=col1;i<col2+1;i++){
            sum+=colsum[row2][i];
            if(row1>0)
                sum-=colsum[row1-1][i];
        }
        return sum;
    }
};
