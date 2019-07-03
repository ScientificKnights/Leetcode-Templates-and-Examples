/*
A message containing letters from A-Z is being encoded to numbers using the following mapping way:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.

Given the encoded message containing digits and the character '*', return the total number of ways to decode it.
Also, since the answer may be very large, you should return the output mod 109 + 7.

Input: "*"
Output: 9

Input: "1*"
Output: 9 + 9 = 18

The length of the input string will fit in range [1, 105].
The input string will only contain the character '*' and digits '0' - '9'.
*/

int numDecodings(string s) {
    if(s[0]=='0') return 0;
    int n=s.size();
    vector<long> dp(n+1);
    dp[0]=1,dp[1]=(s[0]=='*')?9:1;
    for(int i=1;i<n;i++){
        if(s[i]!='*'){
            if(s[i]=='0' && s[i-1]=='0') return 0;
            if(s[i]!='0') dp[i+1]+=dp[i];
            if(s[i-1]=='1' || s[i-1]=='*')
                dp[i+1]=(dp[i-1]+dp[i+1])%1000000007;
            if((s[i-1]=='2' || s[i-1]=='*') && (s[i]>='0' && s[i]<='6'))
                dp[i+1]=(dp[i-1]+dp[i+1])%1000000007;
        }
        else{
            dp[i+1]=(dp[i]*9+dp[i+1])%1000000007;
            if(s[i-1]=='1' || s[i-1]=='*')
                dp[i+1]=(dp[i-1]*9+dp[i+1])%1000000007;
            if(s[i-1]=='2' || s[i-1]=='*')
                dp[i+1]=(dp[i-1]*6+dp[i+1])%1000000007;
        }
    }
    return dp[n];
}
