/*
Serialization is the process of converting a data structure or object into a sequence of bits 
so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later 
in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. 
There is no restriction on how your serialization/deserialization algorithm should work. 
You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized 
to the original tree structure.

Example: 

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
Clarification: The above format is the same as how LeetCode serializes a binary tree. 
You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. 
Your serialize and deserialize algorithms should be stateless.
*/

class Codec {
private:
    //preorder dfs
    void dfs(TreeNode* root,stringstream& ss){
        if(root){
            ss<<' '<<root->val;
            dfs(root->left,ss);
            dfs(root->right,ss);            
        }
        else
            ss<<" #";
        return;
    }
    TreeNode* construct(stringstream& ss){
        string val;
        ss >> val;
        if(val=="#") return NULL;
        else{
            TreeNode* t=new TreeNode(stoi(val));
            t->left=construct(ss);
            t->right=construct(ss);
            return t;
        }
    }
    
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        dfs(root,ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return construct(ss);
    }
};
