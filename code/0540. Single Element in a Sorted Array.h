/*
Given a sorted array consisting of only integers where every element appears exactly twice 
except for one element which appears exactly once. Find this single element that appears only once.
*/

int singleNonDuplicate(vector<int>& nums) {
    int l=0,r=nums.size()-1,mid;
    while(l<=r){
        mid=l+(r-l)/2;
        if(l==r || (nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1] )) return nums[mid];
        if(nums[mid]==nums[mid-1]){
            //[3,3,7,7,10,11,11]
            if((mid-l)%2) l=mid+1;
            //[1,1,2,3,3,4,4,8,8]
            else  r=mid;
        } 
        else{
            //[3,3,5, 7,7,11,11]
            if((mid-l)%2) r=mid-1;
            //[1,1,3,3,4,4,5,8,8]
            else l=mid;
        }
    }
    return nums[mid];
}
