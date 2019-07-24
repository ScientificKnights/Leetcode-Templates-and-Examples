/*
On a horizontal number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], 
where N = stations.length.

Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized.
Return the smallest possible value of D.

Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
Output: 0.500000
Note:
stations.length will be an integer in range [10, 2000].
stations[i] will be an integer in range [0, 10^8].
K will be an integer in range [1, 10^6].
Answers within 10^-6 of the true value will be accepted as correct.
*/

class Solution {
private:
    int helper(vector<int> &diff, double mid){
        int res=0;
        for(auto i:diff){
            res+=(ceil(1.0*i/mid)-1);
        }
        return res;
    }
public:
    double minmaxGasDist(vector<int>& nums, int K) {
        int n=nums.size();
        vector<int> diff(n-1);
        for(int i=0;i<n-1;i++)
            diff[i]=nums[i+1]-nums[i];
        double l=*min_element(diff.begin(),diff.end())*1.0/(K+1), r=*max_element(diff.begin(),diff.end()), mid;
        while(l+0.000001<r){
            mid=l+(r-l)/2.0;
            int count=helper(diff,mid);
            if(count<=K)
                r=mid;
            else
                l=mid;
        }
        return l;
    }
};
