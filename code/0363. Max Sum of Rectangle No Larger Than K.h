/*
Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2 
Explanation: Because the sum of rectangle [[0, 1], [-2, 3]] is 2,
             and 2 is the max number no larger than k (k = 2).
*/

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    //subproblem, max sum of part of vector no larger than K, O(nlogn)
    //naive N^4
    int n=matrix.size();
    if(n==0) return 0;
    int m=matrix[0].size();
    int res=INT_MIN;
    for(int i=0;i<m;i++){
        vector<int> sum(n,0);
        for(int j=i;j<m;j++){    
            //set, lowerbound to find closest to K
            set<int> sums; 
            sums.insert(0);
            int matrix_sum=0;
            for(int row=0;row<n;row++){
                sum[row]+=matrix[row][j];   //sum_k: row k, col i to j.  O(N)=n^2*m
                matrix_sum+=sum[row];
                if(matrix_sum==k) return k;
                auto ii=sums.lower_bound(matrix_sum-k);                   //O(N)=n^2*m*log(m)
                if(ii!=sums.end())
                    res=max(res,matrix_sum-*ii);
                if(res==k) return k;
                sums.insert(matrix_sum);
            }
        }
    }
    return res;
}
