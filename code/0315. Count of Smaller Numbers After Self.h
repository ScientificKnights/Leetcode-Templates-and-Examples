/*
You are given an integer array nums and you have to return a new counts array. 
The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Input: [5,2,6,1]
Output: [2,1,1,0] 
*/

class Solution {
private:
    void mergesort(vector<vector<int>> &data, int l, int r,vector<int> &res){
        if(r-l<=1) return;
        int mid=(r-l)/2+l;
        mergesort(data,l,mid,res);
        mergesort(data,mid,r,res);
        int start=mid;
        for(int i=l;i<mid;i++){
            while(start<r && data[i][0]>data[start][0]) start++;
            res[data[i][1]]+=(start-mid);
        }
        inplace_merge(data.begin()+l,data.begin()+mid,data.begin()+r);
        return;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> data(n,vector<int>(2,0));
        for(int i=0;i<n;i++){
            data[i][0]=nums[i];
            data[i][1]=i;
        }
        vector<int> res(n,0);
        mergesort(data,0,n,res);
        return res;
    }
};
