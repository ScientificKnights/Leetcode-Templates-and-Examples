/*
Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')', 
and in any positions ) so that the resulting parentheses string is valid.

Formally, a parentheses string is valid if and only if:

It is the empty string, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.

Input: "())"
Output: 1

Input: "((("
Output: 3

Input: "()"
Output: 0

Input: "()))(("
Output: 4

S.length <= 1000
S only consists of '(' and ')' characters.
*/

class Solution {
private:
    int helper(string &S, string test){
        int count=0,res=0, n=S.size();
        for(int i=0;i<n;i++){
            if(S[i]==test[0]) count++;
            else if(count>0) count--;
            else res++;
        }
        return res;
    }
public:
    int minAddToMakeValid(string S) {
        int res=helper(S,"()");
        reverse(S.begin(),S.end());
        res+=helper(S,")(");
        return res;
    }
};
