/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
*/
bool isMatch(string s, string p) {
    /*
      adeb
     10000
    *11111 
    a01000
    *00111
    b00001
    */
    int m=s.size(),n=p.size();
    vector<vector<bool>> res(n+1,vector<bool>(m+1,false)); 
    if(m==0 && n==0) return true;
    if(n==0) return false;
    res[0][0]=true;
    //more than one *
    for(int i=0;i<n;i++){
        if(p[i]=='*')
            res[i+1][0]=true;
        else
            break;
    }
    for(int i=1;i<n+1;i++)
        for(int j=1;j<m+1;j++){
            //'*'可以前进0或者1
            if(p[i-1]=='*' &&(res[i-1][j-1]|| res[i-1][j])){
                for(int k=j;k<m+1;k++)
                    res[i][k]=true;
                j=m;
            }
            else if(res[i-1][j-1] && (p[i-1]=='?' || p[i-1]==s[j-1]) )
                res[i][j]=true;
        }
    return res[n][m];
}
