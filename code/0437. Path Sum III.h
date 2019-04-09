/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
*/

class Solution {
private:
    void helper(int &res,TreeNode* root, int sum, int target){
        sum+=root->val;
        if(sum==target)
            res++;
        if(root->left)
            helper(res,root->left,sum,target);
        if(root->right)
            helper(res,root->right,sum,target);
        return;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        int res=0;
        helper(res,root,0,sum);
        res+=pathSum(root->left,sum);
        res+=pathSum(root->right,sum);
        return res;
    }
};
