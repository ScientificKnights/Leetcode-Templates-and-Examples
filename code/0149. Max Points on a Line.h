/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Example 1:

Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
Example 2:

Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/

int maxPoints(vector<vector<int>>& points) {
    int n=points.size(),res=0;
    if(n<=1) return n;
    for(int i=0;i<n;i++){
        unordered_map<int,unordered_map<int,int>> m;
        int equal=0,cur_res=0;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(points[i][0]==points[j][0] && points[i][1]==points[j][1]) // 相同的点要单独考虑
                equal++; 
            else if(points[i][0]==points[j][0])   
                cur_res=max(cur_res,++m[INT_MAX][INT_MAX]);
            else {
                int g=__gcd(points[j][1]-points[i][1],points[j][0]-points[i][0]);
                cur_res=max(cur_res,++m[(points[j][1]-points[i][1])/g][(points[j][0]-points[i][0])/g]);
            }
        }
        res=max(cur_res+equal,res);
    }
    return res+1;
}
