/*
You have d dice, and each die has f faces numbered 1, 2, ..., f.

Return the number of possible ways (out of fd total ways) modulo 10^9 + 7 to roll the dice 
so the sum of the face up numbers equals target.

Input: d = 1, f = 6, target = 3
Output: 1

Input: d = 2, f = 6, target = 7
Output: 6

Input: d = 2, f = 5, target = 10
Output: 1

Input: d = 1, f = 2, target = 3
Output: 0

Input: d = 30, f = 30, target = 500
Output: 222616187

Constraints:

1 <= d, f <= 30
1 <= target <= 1000
*/

int numRollsToTarget(int d, int f, int target) {
    vector<int> dp(target+1,0);
    dp[0]=1;
    for(int i=0;i<d;i++){
        if(i==1) dp[0]=0; // d=2, f=1, target=1; d不能大于target
        vector<int> temp(target+1,0);
        for(int k=1;k<=f;k++){
            for(int j=0;j<=target-k-(d-i)+1 && j<=i*f;j++){
                if(dp[j])
                    temp[j+k]=(dp[j]+temp[j+k])%(1000000007);
            }
        }
        dp=temp;
    }
    return dp[target];
}
