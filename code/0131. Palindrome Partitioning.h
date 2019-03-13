/*
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

Input: "aab"
Output: [  ["aa","b"],  ["a","a","b"] ]
*/

bool ispalindrome(const string &s,int begin,int end){
    while(begin<end)
        if(s[begin++]!=s[end--])
            return false;
    return true;
}
void helper(vector<vector<string>> &res,const string &s,vector<string> &path,int cur){
    if(cur==s.size()){
        res.push_back(path);
        return;
    }
    for(int i=cur;i<s.size();i++){
        if(ispalindrome(s,cur,i)){
            path.push_back(s.substr(cur,i-cur+1));
            helper(res,s,path,i+1);
            path.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    if(s.size()==0) return res;
    vector<string> path;
    helper(res,s,path,0);
    return res;
}
