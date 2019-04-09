/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, 
called the "root." Besides the root, each house has one and only one parent house. 
After a tour, the smart thief realized that "all houses in this place forms a binary tree". 
It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Input: [3,2,3,null,3,null,1]
     3
    / \
   2   3
    \   \ 
     3   1
Output: 7 

Input: [3,4,5,1,3,null,1]
     3
    / \
   4   5
  / \   \ 
 1   3   1
Output: 9
*/

class Solution {
private:
    vector<int> helper(TreeNode* root){
        //返回vector，包含和不包含,T: O(N)
        if(!root) return {0,0};
        vector<int> res={root->val,0};
        if(root->left){
            vector<int> l=helper(root->left);
            res[0]+=l[1];
            res[1]+=max(l[0],l[1]);     //可以包含left 或者不包含
        }
        if(root->right){
            vector<int> r=helper(root->right);
            res[0]+=r[1];
            res[1]+=max(r[0],r[1]);
        }
        return res;
    }
public:
    int rob(TreeNode* root) {
        vector<int> res=helper(root);
        return max(res[0],res[1]);
    }
};
