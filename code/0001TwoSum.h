class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int,int> hash;
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
            int tofind=target-nums[i];
            if(hash.count(tofind)!=0)
            {
                result.push_back(hash[tofind]);
                result.push_back(i);
                return result;
            }
            hash[nums[i]]=i;
        }
        return result;
    }
};
