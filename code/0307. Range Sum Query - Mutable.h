/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.

Example:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:

The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
*/

struct SegTreeNode{
    int sum,start,end;
    SegTreeNode* left;
    SegTreeNode* right;
    SegTreeNode(int a,int b):start(a),end(b),sum(0){}
};

class NumArray {
private:
    SegTreeNode* root;
    
    SegTreeNode* build(vector<int> &nums, int a,int b){
        SegTreeNode* t=new SegTreeNode(a,b);
        if(a==b){
            t->sum=nums[a];
        }
        else{
            int mid=(a+b)/2;
            t->left=build(nums,a,mid);
            t->right=build(nums,mid+1,b);
            t->sum=t->left->sum+t->right->sum;
        }
        return t;
    }
    
    //返回diff
    int modify(SegTreeNode* t,int i,int val){
        if(t->start==t->end){
            int diff=val-t->sum;
            t->sum=val;
            return diff;
        }
        int diff;
        if(t->left->end>=i) diff=modify(t->left,i,val);
        else diff=modify(t->right,i,val);
        t->sum+=diff;
        return diff;
    }
    
    int getsum(SegTreeNode *t,int i,int j){
        if(i>t->end || j<t->start) return 0;
        if(i<=t->start && j>=t->end) return t->sum;
        return getsum(t->left,i,j)+getsum(t->right,i,j);
    }
public:
    NumArray(vector<int> nums) {
        if(nums.size()!=0) 
            root=build(nums,0,nums.size()-1);
    }
    
    void update(int i, int val) {
        modify(root,i,val);
        return;
    }
    
    int sumRange(int i, int j) {
        return getsum(root,i,j);
    }
};
