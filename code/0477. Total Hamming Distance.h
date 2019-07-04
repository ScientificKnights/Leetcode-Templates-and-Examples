/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Now your job is to find the total Hamming distance between all pairs of the given numbers.

Input: 4, 14, 2
Output: 6

Note:
Elements of the given array are in the range of 0 to 10^9
Length of the array will not exceed 10^4.
*/

int totalHammingDistance(vector<int>& nums) {
    int n=nums.size(), res=0;
    if(n<=1) return 0;
    while(true){
        int zero=0,count_0=0,count_1=0;
        for(int i=0;i<n;i++){ 
            if(nums[i]%2) count_1++;
            else count_0++;
            nums[i]=nums[i]>>1;
            if(!nums[i]) zero++;
        }
        res+=count_0*count_1;
        if(zero==n) break;
    }
    return res;
}
