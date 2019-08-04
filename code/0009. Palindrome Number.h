/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
*/

class Solution {
public:
    bool isPalindrome(int x) 
    {
        //先算出来多少位
        if (x < 0) return false;
        int div = 1;
        while (x / div >= 10)
            div *= 10;
        while (x != 0)
        {
            int l = x / div;
            int r = x % 10;
            if (l != r) return false;
            x = (x % div) / 10;
            div /= 100;
        }
        return true;
    }
    /*
    bool isPalindrome(int x) 
    {
        //先算出来多少位
        if (x < 0) return false;
        string s=to_string(x);
        int start=0,end=s.size()-1;
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++,end--;
        }
        return true;
    }
    */
};
