/*
Given a string S, return the number of substrings of length K with no repeated characters.

Input: S = "havefunonleetcode", K = 5
Output: 6

Input: S = "home", K = 5
Output: 0

1 <= S.length <= 10^4
All characters of S are lowercase English letters.
1 <= K <= 10^4
*/

int numKLenSubstrNoRepeats(string S, int K) {
    int n=S.size(),start=0,res=0;
    vector<int> count(26,0);
    for(int i=0;i<n;i++){
        count[S[i]-'a']++;
        if(i-K+1>start)
            count[S[start++]-'a']--;
        while(count[S[i]-'a']>1)
            count[S[start++]-'a']--;
        if(i-start==K-1) res++;
    }
    return res;
}
