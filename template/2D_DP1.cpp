//需要考虑有一个没有(size多一个),这样初始化第一行/列，一定要先尝试这样用
vector<vector<int>> dp(n+1,vector<int>(m+1,0));
dp[0][0]= //单独初始化，如果之后初始化公式会越界
for(int i=1;i<m+1;i++){初始化第一行}
//如何初始化第一行/列都需要某个参数，在这里reset
for(int i=1;i<n+1;i++){初始化第一列}

for(int i=1;i<n+1;i++)
  for(int j=1;j<m+1;j++){
	   //根据路径定义dp[i][j]
	   //例如 lc 72 edit distance, 
            if(s1[i-1]==s2[j-1])// 第一种办法定义，注意减去1
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=min(dp[i-1][j]+s1[i],dp[i][j-1]+s2[j]);
    }
return dp[n][m];
