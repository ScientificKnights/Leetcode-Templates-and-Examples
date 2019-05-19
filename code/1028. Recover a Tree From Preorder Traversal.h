/*
We run a preorder depth first search on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  
(If the depth of a node is D, the depth of its immediate child is D+1.  The depth of the root node is 0.)

If a node has only one child, that child is guaranteed to be the left child.
Given the output S of this traversal, recover the tree and return its root.

Input: "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
*/

//iterative 12ms
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
                vector<TreeNode*> stack;
        for (int i = 0, level, val; i < S.length();) {
            for (level = 0; S[i] == '-'; i++)
                level++;
            for (val = 0; i < S.length() && S[i] != '-'; i++)
                val = val * 10 + S[i] - '0';
            TreeNode* node = new TreeNode(val);
            while (stack.size() > level) stack.pop_back();
            if (!stack.empty())
                if (!stack.back()->left) stack.back()->left = node;
                else stack.back()->right = node;
            stack.emplace_back(node);
        }
        return stack[0];
    }
};


//recursive 16ms
class Solution {
private:
    void helper(TreeNode* &root, const string &s, int level, int &start){
        int i=start;
        while(s.size()>i && s[i]=='-')
            i++;
        if(level==i-start){
            int j=i;
            while(s.size()>i && isdigit(s[i]))
                i++;
            int num=stoi(s.substr(j,i-j));
            start=i;
            root= new TreeNode(num);
            helper(root->left, s, level+1, start);
            helper(root->right, s, level+1, start);
        }
        return;
    }
public:
    TreeNode* recoverFromPreorder(string S) {
        TreeNode* res=NULL;
        int start=0;
        helper(res,S,0,start);
        return res;
    }
};
