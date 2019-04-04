/*
Given an integer matrix, find the length of the longest increasing path.
From each cell, you can either move to four directions: left, right, up or down. 
You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Input: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
Output: 4 
Explanation: The longest increasing path is [1, 2, 6, 9].
*/

class Solution {
public:
    	int dfs(vector<vector<int>>& matrix,vector<vector<int>>& visited,int i,int j){
		if(visited[i][j]>0) return visited[i][j];
		int n=matrix.size();
			int m=matrix[0].size();
			visited[i][j]=1;
			vector<int> pos={1,0,-1,0,1};
			for(int k=0;k<4;k++){
				int y=i+pos[k],x=j+pos[k+1];
				if(y>-1 && y<n && x>-1 && x<m && matrix[y][x]>matrix[i][j])
			visited[i][j]=max(visited[i][j], 1+dfs(matrix,visited,y,x));
		}
		return visited[i][j];
	}
	int longestIncreasingPath(vector<vector<int>>& matrix){
		int n=matrix.size();
		if(n==0) return 0;
		int m=matrix[0].size(),maxlen=0;
		vector<vector<int>> visited(n,vector<int>(m,0));
		//dfs position
		
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				if(visited[i][j]==0)
					maxlen=max(maxlen,dfs(matrix,visited,i,j));
			}
		return maxlen;
	}
};
