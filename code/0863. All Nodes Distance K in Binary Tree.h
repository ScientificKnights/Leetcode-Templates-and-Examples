/*
We are given a binary tree (with root node root), a target node, and an integer value K.
Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]
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
struct GraphNode{
    int val;
    GraphNode *left;
    GraphNode *right;
    GraphNode *up;
    GraphNode(int x):val(x),left(NULL),right(NULL),up(NULL) {}
};

class Solution {
private:
    GraphNode* TreetoGraph(TreeNode* root, GraphNode* top, int target, GraphNode* &find){
        if(!root) return NULL;
        GraphNode* cur=new GraphNode(root->val);
        cur->up=top;
        cur->left=TreetoGraph(root->left,cur,target,find);
        cur->right=TreetoGraph(root->right,cur,target,find);
        if(cur->val==target) find=cur;
        return cur;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        GraphNode* find=NULL;
        TreetoGraph(root, NULL,target->val,find);
        if(K==0) return {find->val};
        vector<int> res;
        int level=1;
        //bfs graph, 防止走回去
        unordered_set<int> visited;
        queue<GraphNode*> q;
        q.push(find);
        while(!q.empty()){
            int k=q.size();
            for(int i=0;i<k;i++){
                GraphNode* cur=q.front();
                visited.insert(cur->val);
                q.pop();
                if(level==K){       //find res
                    if(cur->left && !visited.count(cur->left->val)) 
                        res.push_back(cur->left->val);
                    if(cur->right && !visited.count(cur->right->val)) 
                        res.push_back(cur->right->val);
                    if(cur->up && !visited.count(cur->up->val)) 
                        res.push_back(cur->up->val);
                }
                else{               //increase level
                    if(cur->left && !visited.count(cur->left->val)) 
                        q.push(cur->left);
                    if(cur->right && !visited.count(cur->right->val)) 
                        q.push(cur->right);
                    if(cur->up && !visited.count(cur->up->val)) 
                        q.push(cur->up);
                }
            }
            level++;
        }
        return res;
    }
};
