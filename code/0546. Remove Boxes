/*
Given several boxes with different colors represented by different positive numbers. 
You may experience several rounds to remove boxes until there is no box left. 
Each time you can choose some continuous boxes with the same color (composed of k boxes, k >= 1), 
remove them and get k*k points.
Find the maximum points you can get.

Input:
[1, 3, 2, 2, 2, 3, 4, 3, 1]
Output:
23
Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
----> [1, 3, 3, 3, 1] (1*1=1 points) 
----> [1, 1] (3*3=9 points) 
----> [] (2*2=4 points)
Note: The number of boxes n would not exceed 100.
*/

class Solution {
    //need third dimension to keep track the current length of continuous same color box(same as the last box).
private:
    int dp[100][100][100];
public:
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        return dfs(boxes,0,n-1,0);
    }
    
    int dfs(vector<int>& boxes,int l,int r,int k){
        if (l>r) return 0;
        if (dp[l][r][k]!=0) 
            return dp[l][r][k];
        
        //k meaning 最后个数字有k个相等的
        while (r>l && boxes[r]==boxes[r-1]) 
        {   
            r--;
            k++;
        }
        dp[l][r][k] = dfs(boxes,l,r-1,0) + (k+1)*(k+1); //2221221211 可能要提前消后面的，其实前面有相等的
        for (int i=l; i<r; i++){
            if (boxes[i]==boxes[r]){    //1 2 1 3 1 -> 1 2 1 1 (0,2,2) +3 or  1 2 1 3 (0,3,0) + 1
                dp[l][r][k]=max(dp[l][r][k],dfs(boxes,l,i,k+1)+dfs(boxes,i+1,r-1,0));
            }
        }
        return dp[l][r][k];
    }
};
