/*
Given a non-empty string check if it can be constructed by taking a substring of it 
and appending multiple copies of the substring together. 
You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.
*/

bool repeatedSubstringPattern(string s) {
    string twos=s+s;
    return twos.substr(1,s.size()*2-2).find(s)!=string::npos;
}
