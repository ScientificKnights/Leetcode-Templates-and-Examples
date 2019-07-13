/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
*/

class Solution {
public:
    //3 1 3 2 2
    int helper(vector<int> &nums){
        int res=INT_MIN;
        stack<int> s;
        s.push(-1);
        int n=nums.size();
        //一个比一个大等于，前面的数是截至位置
        for(int i=0;i<n;i++){
            if(s.size()<=1 || (nums[i]>=nums[s.top()]) ) s.push(i);
            else{
                while(s.size()>1 && nums[s.top()]>nums[i]){
                    int top=nums[s.top()];
                    s.pop();
                    res=max(res,(i-s.top()-1)*top);
                }
                s.push(i);
            }
        }
        //还剩下
        while(s.size()>1){
            int top=nums[s.top()];
            s.pop();
            res=max(res,(n-s.top()-1)*top);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        //largest rectangle in Histogram
        int n=matrix.size();
        if(n==0) return 0;
        int m=matrix[0].size();
        vector<vector<int>> data(n,vector<int>(m,0));
        
        for(int j=0;j<m;j++)
            data[0][j]=matrix[0][j]-'0';
        
        for(int i=1;i<n;i++)
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0') data[i][j]=0;
                else data[i][j]=1+data[i-1][j];
            }
        int res=helper(data[0]);

        for(int i=1;i<n;i++)
            res=max(res,helper(data[i]));

        return res;
    }
};
