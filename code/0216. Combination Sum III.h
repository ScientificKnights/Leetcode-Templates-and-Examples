/*
Find all possible combinations of k numbers that add up to a number n, 
given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/

void helper(vector<vector<int>> &res,vector<int> &path,int target, int length, int cur){
    if(target==0 && length==0){
        res.push_back(path);
        return;
    }
    if(length==0)
        return;
    for(int i=cur; i<10 && target>=(i+i+length-1)*length/2;i++){
        path.push_back(i);
        helper(res,path,target-i,length-1,i+1);
        path.pop_back();
    }
    return;
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> path;
    helper(res,path,n,k,1);
    return res;
}
