/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,
return 13.
*/

int helper(vector<vector<int>>& matrix, int target){  //返回小于等于target的个数
  int n=matrix.size(),m=matrix[0].size();
  int i=0,j=m-1;
  int sum=0;
  while(i<n && j>=0){
      if(matrix[i][j]>target)
          j--;
      else{
          sum+=(j+1);
          i++;
      }
  }
  return sum;
}

int kthSmallest(vector<vector<int>>& matrix, int k) {
  int n=matrix.size();
  int m=matrix[0].size();
  int start=matrix[0][0],end=matrix[n-1][m-1]+1;
  int mid;
  while(start<end){
      mid=start+(end-start)/2;
      int count=helper(matrix,mid);
      if(count>=k)      //大于等于mid时，count(mid)大于等于k
          end=mid;
      else
          start=mid+1;
  }
  return start;         
}
