/*
For strings S and T, we say "T divides S" if and only if S = T + ... + T  (T concatenated with itself 1 or more times)
Return the largest string X such that X divides str1 and X divides str2.

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""
*/

string gcdOfStrings(string str1, string str2) {
    if(str1.size()>str2.size())
        return gcdOfStrings(str2,str1);
    if(str1=="") return str2;
    if(str2.substr(0,str1.size())!=str1) return "";
    return gcdOfStrings(str2.substr(str1.size()),str1);
}
