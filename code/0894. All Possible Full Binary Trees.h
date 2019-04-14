/*
A full binary tree is a binary tree where each node has exactly 0 or 2 children.
Return a list of all possible full binary trees with N nodes. 
Each element of the answer is the root node of one possible tree.
Each node of each tree in the answer must have node.val = 0.
You may return the final list of trees in any order.

Input: 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],
        [0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
*/

vector<TreeNode*> allPossibleFBT(int N) {
    vector<TreeNode*> res;
    if(N==0 || N%2==0) return res;
    if(N==1){
        res.emplace_back(new TreeNode(0));
        return res;
    }
    for(int k=1;k<=(N-1)/2;k+=2){
        vector<TreeNode*> l=allPossibleFBT(k), r=allPossibleFBT(N-1-k);

        for(int i=0;i<l.size();i++){
            for(int j=0;j<r.size();j++){
                res.emplace_back(new TreeNode(0));
                res.back()->left=l[i];
                res.back()->right=r[j];
            }
        }
        //利用对称性
        if(k!=(N-1)/2){
            for(int i=0;i<l.size();i++){
                for(int j=0;j<r.size();j++){
                    res.emplace_back(new TreeNode(0));
                    res.back()->right=l[i];
                    res.back()->left=r[j];

                }
            }
        }
    }
    return res;
}
