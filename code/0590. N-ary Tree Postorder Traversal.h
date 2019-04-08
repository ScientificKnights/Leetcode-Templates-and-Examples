/*
Given an n-ary tree, return the postorder traversal of its nodes' values.
Note:
Recursive solution is trivial, could you do it iteratively?
*/
vector<int> postorder(Node* root) {
    Node* cur=root;
    vector<int> res;
    stack<Node*> s;
    while(cur || !s.empty()){
        if(cur){
            res.push_back(cur->val);
            for(auto i: cur->children)
                if(i)
                    s.push(i);
            cur=NULL;
        }
        else{
            cur=s.top();
            s.pop();
        }
    }
    reverse(res.begin(),res.end());
    return res;
}
