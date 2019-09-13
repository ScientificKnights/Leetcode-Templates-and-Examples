/*
In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space.
These characters divide the square into contiguous regions.

(Note that backslash characters are escaped, so a \ is represented as "\\".)
Return the number of regions.

Input:
[
  " /",
  "/ "
]
Output: 2
Explanation: The 2x2 grid is as follows:

Input:
[
  " /",
  "  "
]
Output: 1
Explanation: The 2x2 grid is as follows:

Input:
[
  "\\/",
  "/\\"
]
Output: 4
Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
The 2x2 grid is as follows:

Input:
[
  "/\\",
  "\\/"
]
Output: 5
Explanation: (Recall that because \ characters are escaped, "/\\" refers to /\, and "\\/" refers to \/.)
The 2x2 grid is as follows:

Input:
[
  "//",
  "/ "
]
Output: 3
Explanation: The 2x2 grid is as follows:

Note:
1 <= grid.length == grid[0].length <= 30
grid[i][j] is either '/', '\', or ' '.
*/

class Solution {
private:
    vector<int> pos={1,0,-1,0,1};
    
    void dfs(vector<vector<int>> &graph, int r, int c){
        graph[r][c]=1;
        for(int k=0;k<4;k++){
            int x=r+pos[k],y=c+pos[k+1];
            if(x>=0 && y>=0 && x<graph.size() && y<graph[0].size() && !graph[x][y])
                dfs(graph,x,y);
        }
        return;
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        //every symbol to 3*3
        int n=grid.size(),m=grid[0].size(),res=0;
        vector<vector<int>> graph(n*3,vector<int>(m*3,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='/'){
                    graph[3*i][3*j+2]=1; graph[3*i+1][3*j+1]=1; graph[3*i+2][3*j]=1; 
                }
                if(grid[i][j]=='\\'){    
                    graph[3*i][3*j]=1; graph[3*i+1][3*j+1]=1; graph[3*i+2][3*j+2]=1; 
                }
            }
        }
        for(int i=0;i<3*n;i++)
            for(int j=0;j<3*m;j++){
                if(graph[i][j]!=1){
                    dfs(graph,i,j);
                    res++;
                }
            }
        return res;
    }
};
