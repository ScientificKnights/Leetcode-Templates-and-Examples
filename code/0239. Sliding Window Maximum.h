/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position. 
Return the max sliding window.

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 */

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //Monotonic queue;
    //比已有的都大，放前面；不然的话deque，后面pop
    deque<pair<int,int>> dq;
    vector<int> res;
    for(int i=0;i<nums.size();i++){
        //如果大，加前面
        if(dq.empty()||dq.front().first<=nums[i]) 
            dq.push_front(make_pair(nums[i],i));
        //如果小，后面pop，因为用不上了
        else{
            while(dq.back().first<=nums[i]) 
                dq.pop_back();
            dq.push_back(make_pair(nums[i],i));
        }
        //可能不靠后的大数在前面，删除
        while(dq.front().second<=i-k) dq.pop_front();
        if(i>=k-1)
            res.push_back(dq.front().first);
    }
    return res;
}
