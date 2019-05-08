/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers 
and operators. The valid operators are +, - and *.

Input: "2-1-1"
Output: [0, 2]
Explanation: 
((2-1)-1) = 0 
(2-(1-1)) = 2

Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
*/

class Solution {
private:
    void stov(vector<int> &nums, vector<char> &ops, const string &input){
        int n=input.size();
        for(int i=0;i<n;){
            if(!isdigit(input[i])) ops.push_back(input[i++]);
            else{
                int j=i;
                while(isdigit(input[j])) j++;
                nums.push_back(stoi(input.substr(i,j-i)));
                i=j;
            }
        }
        return;
    }
    void helper(vector<vector<vector<int>>> &dp, vector<char> &ops, int l, int r){
        for(int i=l;i<=r-1;i++){
            vector<int> left=dp[l][i],right=dp[i+1][r];
            for(int j=0;j<left.size();j++)
                for(int k=0;k<right.size();k++){
                    if(ops[i]=='+') dp[l][r].push_back(left[j]+right[k]);
                    else if(ops[i]=='-') dp[l][r].push_back(left[j]-right[k]);
                    else dp[l][r].push_back(left[j]*right[k]);
                }
        }
        return;
    }
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        vector<char> ops;
        stov(nums,ops,input);
        int m=nums.size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(m));
        for(int i=0;i<m;i++)
            dp[i][i].push_back(nums[i]);
        for(int r=1;r<m;r++){
            for(int l=r-1;l>=0;l--){
                helper(dp,ops,l,r);
            }
        }
        return dp[0][m-1];
    }
};
