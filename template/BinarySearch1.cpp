/*
Given a sorted (in ascending order) integer array nums of n elements and a target value, 
write a function to search target in nums. If target exists, then return its index, otherwise return -1.
*/

int left=0,right=n,mid;		//r要保证大于target，所以是界外n,不是n-1
while(left<right){		//要保证要找的在start，end里[l,r)
    mid=left+(right-left)/2;	//防止越界，要用减法
    if(nums[mid]==target)	return mid;	//因为不一定找到，所以while里返回
    else if(nums[mid]>target)	right=mid;	//先判断右侧，不能相等
    else			left=mid+1;	//l最后要换号，所以+1，以便和mid符号(<T)不等
}
return -1;				//没有相等，返回-1

//-------------------------------------------------------------------------

int left=0,right=n-1,mid;   //r大于等于target
while(left<=right){         //要找的在[l,r]里
    mid=left+(right-left)/2;
    if(nums[mid]==target)
        return mid;
    else if(nums[mid]>target)
        right=mid-1;
    else
        left=mid+1;
}
return -1;
