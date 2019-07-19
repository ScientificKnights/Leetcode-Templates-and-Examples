/*
Given a matrix of integers A with R rows and C columns, find the maximum score of a path starting at [0,0] 
and ending at [R-1,C-1].

The score of a path is the minimum value in that path.  For example, the value of the path 8 →  4 →  5 →  9 is 4.
A path moves some number of times from one visited cell to any neighbouring unvisited cell 
in one of the 4 cardinal directions (north, east, west, south).

Input: [[5,4,5],[1,2,6],[7,4,6]]
Output: 4

Input: [[2,2,1,2,2,2],[1,2,2,2,1,2]]
Output: 2

Input: [[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]
Output: 3

Note:
1 <= R, C <= 100
0 <= A[i][j] <= 10^9
*/

class Solution {
private:
    bool connect(vector<vector<int>> A, int mid){
        int n=A.size(),m=A[0].size();
        queue<pair<int,int>> q;
        q.push({0,0});
        A[0][0]=-1;
        vector<int> pos={1,0,-1,0,1};
        while(!q.empty()){
            int r=q.front().first,c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x=pos[i]+r,y=pos[i+1]+c;
                if(x>=0 && x<n && y>=0 && y<m && A[x][y]>=mid){
                    if(x==n-1 && y==m-1) return true;
                    A[x][y]=-1;
                    q.push({x,y});
                }
            }
        }
        return false;
    }
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int n=A.size(),m=A[0].size();
        if(n==m && m==1) return A[0][0];
        int l=0,r=1e9+1,mid;
        while(l<r){
            mid=l+(r-l)/2;
            if(connect(A,mid))
                l=mid+1;
            else
                r=mid;
        }
        return min(l-1,A[0][0]);
    }
};
