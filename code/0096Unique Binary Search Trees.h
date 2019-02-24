/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   */
int numTrees(int n) {
     //BST 特征，如果k是root， 1 to k-1在左，k+1 to n 在右侧
     //F(n)=F(0)*F(n-1)+F(1)*F(n-2)+..+F(n-1)F(0)
     if(n==0 ) return 1;
     vector<int> nums(n+1,0);
     nums[0]=1;
     for(int i=1;i<n+1;i++)
         for(int j=0;j<=i-1;j++)
             nums[i]+=nums[j]*nums[i-1-j];
     return nums[n];
}
