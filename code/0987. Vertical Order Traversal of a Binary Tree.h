/*
Given a binary tree, return the vertical order traversal of its nodes values.
For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).
Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, 
we report the values of the nodes in order from top to bottom (decreasing Y coordinates).
If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.
Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.
*/

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int,vector<pair<int,int>>> m;       //col <val, row>
    queue<pair<TreeNode*,int>> q;
    if(root) q.push(make_pair(root,0));
    int level=0;
    while(!q.empty()){
        int k=q.size();
        for(int i=0;i<k;i++){
            pair<TreeNode*,int> cur=q.front();
            m[cur.second].push_back({cur.first->val,level});
            q.pop();
            if(cur.first->left) q.push(make_pair(cur.first->left,cur.second-1));
            if(cur.first->right) q.push(make_pair(cur.first->right,cur.second+1));
        }
        level++;
    }
    vector<vector<int>> res;
    for(auto i: m){
        sort(i.second.begin(),i.second.end(),[](pair<int,int> &a, pair<int,int> &b){        //如果row相同，比较数值
            return (a.second<b.second)||(a.second==b.second&&a.first<b.first);
        });
        res.push_back({});
        for(auto j:i.second)
            res[res.size()-1].push_back(j.first);
    }
    return res;
}
