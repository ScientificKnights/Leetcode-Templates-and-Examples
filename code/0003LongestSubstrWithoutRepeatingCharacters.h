/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
    //模板，map存key和position，更新start的值，是map中position下一个数字，更新map，更新res
        unordered_map<int,int> m;
        int start=0,res=0;
        for(int i=0;i<s.size();i++){
            //更新start
            if(m.count(s[i])!=0)
                start=max(start,m[s[i]]+1);
            //更新map
            m[s[i]]=i;
            //更新res
            res=max(res,i-start+1);
        }
        return res;
    }
};
