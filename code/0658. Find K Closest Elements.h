/*
Given a sorted array, two integers k and x, find the k closest elements to x in the array. 
The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 104
*/

class Solution {
public:
    // binary search
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left=0,right=arr.size()-k,mid;  //right 不能到界外
        while(left<right){
            mid=left+(right-left)/2;
            if(arr[mid+k]-x>=x-arr[mid]) right=mid; //arr[mid+k]是右侧没选的数字，保证尽可能选左侧的
            else left=mid+1;
        }
        return vector<int>(arr.begin()+left,arr.begin()+left+k);
    }
};
/* two pointer
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        auto jj=lower_bound(arr.begin(), arr.end(), x);
        if(jj==arr.end()){
            res.insert(res.end(), arr.end()-k,arr.end());
            return res;
        }
        if(jj==arr.begin()){
            res.insert(res.end(), arr.begin(),arr.begin()+k);
            return res;
        }
        // jj 在2-5之间
        if(abs(*prev(jj)-x)<=abs(*jj-x)) jj=prev(jj);
        // jj 在1-5之间
        auto start=jj,end=jj;
        while(end-start<k-1){
            if(start==arr.begin()){
                end++;continue;
            }
            if(next(end)==arr.end()){
                start--;continue;
            }
            if(abs(*prev(start)-x)<=abs(*next(end)-x)) //需要=，返回小的
                start--;
            else
                end++;
        }
        res.insert(res.end(),start,next(end));
        return res;
    }
};
*/
