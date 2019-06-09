/*
Given a matrix consisting of 0s and 1s, we may choose any number of columns in the matrix and flip every cell in that column.  
Flipping a cell changes the value of that cell from 0 to 1 or from 1 to 0.

Return the maximum number of rows that have all values equal after some number of flips.

Input: [[0,0,0],[0,0,1],[1,1,0]]
Output: 2
*/

class Solution {
private:
    void helper(unordered_map<string, int> &m, vector<int> &nums, int &res){
        bool flip=nums[0];
        string s;
        for(auto i:nums)
            s+=('0'+ ((flip)?1-i:i));
        m[s]++;
        res=max(res,m[s]);
    }
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> m;
        int res=0;
        for(int i=0; i< matrix.size();i++)
            helper(m, matrix[i], res);
        return res;
    }
};
