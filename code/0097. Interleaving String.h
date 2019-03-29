/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
*/

bool isInterleave(string s1, string s2, string s3) {
    //DP O(mn) memory O(mn)
    // ab cc abcc
    //     c c
    //   T F F
    // a T F F
    // b T T T
    int n=s1.size();
    int m=s2.size();
    int k=s3.size();
    if(n==0) return s2==s3;
    if(m==0) return s1==s3;
    if(k!=m+n) return false;
    vector<vector<bool>> data(n+1,vector<bool>(m+1,true));
    for(int i=1;i<m+1;i++)
        //前面true并且相等
        data[0][i]=(data[0][i-1] && s2[i-1]==s3[i-1]);
    for(int i=1;i<n+1;i++)
        data[i][0]=(data[i-1][0] && s1[i-1]==s3[i-1]);
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            //前面T并且横着相等 or 上面T并且竖着相等
            if((data[i-1][j]&&s1[i-1]==s3[i+j-1])||(data[i][j-1]&&s2[j-1]==s3[i+j-1]))
                data[i][j]=true;
            else data[i][j]=false;
        }
    }
    return data[n][m];
}
