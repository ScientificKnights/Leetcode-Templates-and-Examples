/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
*/

bool isMatch(string s, string p) {
    //    a a b
    //  1 0 0 0
    //c 0 0 0 0
    //* 1 0 0 0
    //a 0 1 0 0
    //* 1 1 1 0
    //b 0 0 0 1
    int n=p.size(),m=s.size();
    vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
    dp[0][0]=true;
    //如果是 a*b*c* 可以match 空string
    for(int i=0;i<n;i++){
        if(p[i]=='*')
            dp[i+1][0]=dp[i-1][0];
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(p[i]=='*'){
                //-1或者0个
                dp[i+1][j+1]=(dp[i][j+1] || dp[i-1][j+1]);
                //1个或者更多，在左上match的情况，横向增加
                if(dp[i][j]){
                    while(j<m &&(p[i-1]=='.'|| s[j]==p[i-1])){
                        dp[i+1][j+1]=true;
                        j++;
                    }
                }
            }
            //左上match，比较
            else if((p[i]=='.'|| p[i]==s[j]) && dp[i][j]==true)
                dp[i+1][j+1]=true;
        }

    return dp[n][m];
}
