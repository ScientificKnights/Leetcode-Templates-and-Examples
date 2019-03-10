Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

private:
    void helper(vector<vector<int>> &res, vector<int>& nums, int length, int cur){
        if(cur==length-1){
            res.push_back(nums);
            return;
        }
        unordered_map<int,int> used;
        for(int i=cur;i<length;i++){
            //如果swap过相同的就不swap
            if(used.find(nums[i])!=used.end()) continue;
            used[nums[i]]++;
            swap(nums[cur],nums[i]);
            helper(res,nums,length,cur+1);
            swap(nums[cur],nums[i]);  //back_tracking
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //method 2. back_tracking with swap
        vector<vector<int>> res;
        helper(res,nums,nums.size(),0);
        return res;
        /*
        //method 1. next_permutation
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        do{
            res.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return res;*/
    }
