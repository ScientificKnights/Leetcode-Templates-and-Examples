/*
Given a string s that consists of lower case English letters and brackets. 
Reverse the strings in each pair of matching parentheses, starting from the innermost one.
Your result should not contain any bracket.

Input: s = "(abcd)"
Output: "dcba"

Input: s = "(u(love)i)"
Output: "iloveu"

Input: s = "(ed(et(oc))el)"
Output: "leetcode"

Input: s = "a(bcdefghijkl(mno)p)q"
Output: "apmnolkjihgfedcbq"

Constraints:
0 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It's guaranteed that all parentheses are balanced.
*/

string reverseParentheses(string s) {
    int n=s.size();
    vector<string> stacks;
    stacks.push_back("");
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            stacks.push_back("");
        }
        else if (s[i]==')'){
            reverse(stacks.back().begin(),stacks.back().end());
            stacks[stacks.size()-2]+=stacks.back();
            stacks.pop_back();
        }
        else
            stacks.back().push_back(s[i]);
    }
    return stacks[0];
}
