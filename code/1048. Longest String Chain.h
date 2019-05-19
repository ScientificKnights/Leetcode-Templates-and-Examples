/*
Given a list of words, each word consists of English lowercase letters.
Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  
For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, 
where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

Input: ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: one of the longest word chain is "a","ba","bda","bdca".
*/

class Solution {
private:
    bool ischain(const string & a,const string &b){
        int i=0,j=0,res=0;
        for(;i<a.size() && j<b.size();){
            if(a[i]==b[j]) {i++,j++;}
            else{
                if(!res) {res++;i++;}
                else return false;
            }
        }
        return true;
    }
    
public:
    int longestStrChain(vector<string>& words) {
        if(!words.size()) return 0;
        unordered_map<int, unordered_map<string,int>> dp;
        for(auto i:words) dp[i.size()][i]=1;
        int res=1;
        for(int i=2;i<17;i++){
            if(dp[i].size() && dp[i-1].size()){
                for(auto &next:dp[i]){
                    for(auto &prev:dp[i-1]){
                        if(ischain(next.first,prev.first))
                            next.second=max(next.second,prev.second+1);
                    }
                    res=max(res,next.second);
                }
            }
        }
        return res;
    }
};
