/*
Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Input: pattern = "abab", str = "redblueredblue"
Output: true

Input: pattern = pattern = "aaaa", str = "asdasdasdasd"
Output: true

Input: pattern = "aabb", str = "xyzabcxzyabc"
Output: false

Notes:
You may assume both pattern and str contains only lowercase letters.
*/

class Solution {
    bool backtrack(unordered_map<char,string> &ptos,unordered_map<string,char> &stop, const string &pattern, int pos1, const string &str, int pos2){
        int n=pattern.size(),m=str.size();
        
        if(pos1==n && m==pos2) return true;
        if(pos2>=m || pos1>=n) return false;
        if(ptos.count(pattern[pos1])) //必须和之前的match，并且之后也return true
            return str.substr(pos2,ptos[pattern[pos1]].size())==ptos[pattern[pos1]] && backtrack(ptos,stop,pattern, pos1+1,str,pos2+ptos[pattern[pos1]].size());
        for(int l=1;pos2+l-1<m-(n-pos1-1);l++){
            string temp=str.substr(pos2,l);
            if(stop.count(temp)) continue;
            ptos[pattern[pos1]]=temp;
            stop[temp]=pattern[pos1];
            if(backtrack(ptos,stop,pattern,pos1+1,str,pos2+l))
                return true;
            ptos.erase(pattern[pos1]);
            stop.erase(temp);
        }
        return false;
    }
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char,string> ptos;
        unordered_map<string,char> stop; //相同的string不能match不同的字母
        return backtrack(ptos,stop,pattern,0,str,0);
    }
};
