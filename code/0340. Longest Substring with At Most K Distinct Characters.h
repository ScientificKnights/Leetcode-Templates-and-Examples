/*
Given a string, find the length of the longest substring T that contains at most k distinct characters.

Input: s = "eceba", k = 2
Output: 3
*/

int lengthOfLongestSubstringKDistinct(string s, int k) {
    int n=s.size();
    if(n==0 || k==0) return 0;
    unordered_map<char,int> m;
    int start=0;
    int end=0;
    int maxlen=0;
    for(;end<n;end++){
        m[s[end]]+=1;
        while(m.size()>k){
            m[s[start]]--;
            if(m[s[start]]==0)
                m.erase(m.find(s[start]));
            start++;
        }
        maxlen=max(maxlen,end-start+1);
    }
    return maxlen;
}
