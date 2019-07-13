/*
Given a circular array (the next element of the last element is the first element of the array), 
print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Input: [1,2,1]
Output: [2,-1,2]
Note: The length of given array won't exceed 10000.
*/

vector<int> nextGreaterElements(vector<int>& nums) {
    //O(N)
    int n=nums.size();
    vector<int> res(n,-1);
    stack<int> s;

    for(int i=0;i<n;i++){
        if(s.empty() || nums[i]<=nums[s.top()])
            s.push(i);
        else{
            while(!s.empty() && nums[i]>nums[s.top()]){
                res[s.top()]=nums[i];
                s.pop();
            }
            s.push(i);
        }
    }

    for(int i=0;i<n;i++){
        if(s.size()==1) break;
        if(nums[i]>nums[s.top()])
            while( nums[i]>nums[s.top()]){
                res[s.top()]=nums[i];
                s.pop();
            }
    }
    return res;
}
