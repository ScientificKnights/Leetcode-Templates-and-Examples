/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Input: "12"
Output: 2

Input: "226"
Output: 3
*/

int numDecodings(string s) {
    int n=s.size();
    vector<int> res(n+1,0);
    if(n==0)
        return 0;
    //注意考虑‘0’
    if(s[0]=='0')
        return 0;
    res[0]=res[1]=1;

    for(int i=2;i<n+1;i++){
        //注意考虑‘0’
        res[i]=((s[i-1]=='0')?0:res[i-1]);
        if(s[i-2]=='1' || (s[i-2]=='2'&& s[i-1]<='6'))
            res[i]+=res[i-2];
    }
    return res[n];
}
