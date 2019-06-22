/*
A string S represents a list of words.

Each letter in the word has 1 or more options.  If there is one option, the letter is represented as is.  
If there is more than one option, then curly braces delimit the options.  For example, "{a,b,c}" represents options ["a", "b", "c"].
For example, "{a,b,c}d{e,f}" represents the list ["ade", "adf", "bde", "bdf", "cde", "cdf"].

Return all words that can be formed in this manner, in lexicographical order.


Input: "{a,b}c{d,e}f"
Output: ["acdf","acef","bcdf","bcef"]
*/

class Solution {
private:
    void helper(vector<vector<string>> &ss, int pos, string S){
        int n=S.size(),start=pos;
        if(start>=n) return;
        
        while(start<n&& isalpha(S[start])){
            start++;
        }
        if(start!=pos)
            ss[ss.size()-1].push_back(S.substr(pos, start-pos));
        if(start<n && (S[start]=='{' || S[start]=='}')){
           ss.push_back(vector<string>());
            
        }
        helper(ss,start+1,S);
        return;
    }
    void dfs(vector<vector<string>> &ss, vector<string> &res, string temp, int row){
        if(row==ss.size()){res.push_back(temp);return;}
        if(ss[row].size()==0) dfs(ss,res,temp,row+1);
        sort(ss[row].begin(),ss[row].end());
        for(int i=0;i<ss[row].size();i++){
            string temp1=temp;
            dfs(ss,res,temp1+=ss[row][i],row+1);
        }
        return;
    }
public:
    vector<string> expand(string S) {
        vector<vector<string>> ss;
        vector<string> res;
        ss.push_back(vector<string>());
        helper(ss,0,S);
        dfs(ss,res,"",0);
        return res;
    }
};
