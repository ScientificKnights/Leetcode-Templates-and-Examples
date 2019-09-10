/*
Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9,
count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.

Rules for a valid pattern:
Each pattern must connect at least m keys and at most n keys.
All the keys must be distinct.
If the line connecting two consecutive keys in the pattern passes through any other keys,
the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
The order of keys used matters. 

Explanation:
| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |
Invalid move: 4 - 1 - 3 - 6
Line 1 - 3 passes through key 2 which had not been selected in the pattern.

Invalid move: 4 - 1 - 9 - 2
Line 1 - 9 passes through key 5 which had not been selected in the pattern.

Valid move: 2 - 4 - 1 - 3 - 6
Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern

Valid move: 6 - 5 - 4 - 1 - 9 - 2
Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.

Input: m = 1, n = 1
Output: 9
*/

class Solution {
    int backtrack(const vector<vector<int>> &pass,vector<int> &visited, int pos, int cur, int m, int n){
        if(cur==n) {
            return 1;
        }
        int res=(cur>=m)?1:0;
        for(int i=1;i<10;i++){
            if(visited[i]==0 && i!=pos && (pass[pos][i]==0 || visited[pass[pos][i]])){
                visited[i]=1;
                res+=backtrack(pass,visited,i,cur+1,m,n);
                visited[i]=0;
            }
        }
        return res;
    }
public:
    int numberOfPatterns(int m, int n) {
        int res=0;
        vector<int> visited(10,0);
        vector<vector<int>> pass(vector<vector<int>>(10,vector<int>(10,0)));
        pass[1][3]=pass[3][1]=2;
        pass[1][7]=pass[7][1]=4;
        pass[3][9]=pass[9][3]=6;
        pass[9][7]=pass[7][9]=8;
        pass[1][9]=pass[9][1]=pass[3][7]=pass[7][3]=pass[2][8]=pass[8][2]=pass[4][6]=pass[6][4]=5;

        visited[1]=1;
        res+=backtrack(pass,visited,1,1,m,n)*4; //1=3=7=9
        visited[1]=0,visited[2]=1;
        res+=backtrack(pass,visited,2,1,m,n)*4; //2=4=6=8
        visited[2]=0,visited[5]=1;
        res+=backtrack(pass,visited,5,1,m,n);   //5

        return res;
    }
};
