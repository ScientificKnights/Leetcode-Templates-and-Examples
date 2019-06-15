/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/

string minWindow(string s, string t) {
    //record elements in t
    unordered_map<char,int> m;
    for(auto ii:t)
        m[ii]++;
    string res="";
    //count means how many char is not fully covered
    int count=m.size(),start=0;

    for(int i=0;i<s.size();i++){
        if(m.count(s[i])){
            m[s[i]]--;
            if(m[s[i]]==0) count--;
        }
        while(count==0 && start<=i){
            if(res=="" || i-start+1<res.size())
                res=s.substr(start,i-start+1);
            if(m.count(s[start])){
                m[s[start]]++;
                if(m[s[start]]==1) count++;
            }
            start++;
        }
    }
    return res;
}
