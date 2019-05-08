/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

//backtrack
class Solution {
public:
    void backtrack(vector<string> &res, string &path, int left, int right, int total){
        if(left+right==total){
            res.push_back(path);
            return;
        }
        if(left>right){
            path+=')';
            backtrack(res,path,left,right+1,total);
            path.pop_back();
        }
        if(left<total/2){
            path+='(';
            backtrack(res,path,left+1,right,total);
            path.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path="";
        backtrack(res,path,0,0,2*n);
        return res;
    }
};
