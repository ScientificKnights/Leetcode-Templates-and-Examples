/*
You have some coins.  The i-th coin has a probability prob[i] of facing heads when tossed.
Return the probability that the number of coins facing heads equals target if you toss every coin exactly once.

Input: prob = [0.4], target = 1
Output: 0.40000

Input: prob = [0.5,0.5,0.5,0.5,0.5], target = 0
Output: 0.03125
 
Constraints:
1 <= prob.length <= 1000
0 <= prob[i] <= 1
0 <= target <= prob.length
Answers will be accepted as correct if they are within 10^-5 of the correct answer.
*/

double probabilityOfHeads(vector<double>& prob, int target) {
    vector<double> res(target+1,0);
    res[0]=1.0;
    int n=prob.size();
    if(n<target) return 0;
    for(int i=1;i<=n;i++){
        for(int j=min(target,i);j>0;j--){
            res[j]=res[j]*(1.0-prob[i-1])+res[j-1]*prob[i-1];
        }
        res[0]*=(1.0-prob[i-1]);
    }
    return res[target];
}
