/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

class Solution {
public:
    string longestPalindrome(string s) {
    //从start到end，都是和i相同的，下一个i从end+1开始
        if(s.empty())   return s;
        if(s.size()<2)  return s;
        int len=s.size(), min_start=0,max_len=1;
        
        for(int i=0; i<len && len-i>max_len/2; )
        {
            int start=i,end=i;  //起始点
            while(end<len-1&&s[end+1]==s[end])
                end++;      //skip 重复的
            i=end+1;
            while(end<len-1 && start>0 && s[end+1]==s[start-1])
            {
                start--;end++;      //expand
            }
            int new_len=end-start+1;
            if(new_len>max_len)
            {
                min_start=start;
                max_len=new_len;
            }
        }
        
        return s.substr(min_start,max_len);
    }
};
