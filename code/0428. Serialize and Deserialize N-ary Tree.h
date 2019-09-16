/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file
or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize an N-ary tree. An N-ary tree is a rooted tree
in which each node has no more than N children. There is no restriction on how your serialization/deserialization algorithm should work.
You just need to ensure that an N-ary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following 3-ary tree
 
as [1 [3[5 6] 2 4]]. You do not necessarily need to follow this format, so please be creative
and come up with different approaches yourself.

Note:
N is in the range of [1, 1000]
Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
    Node* helper(stringstream &ss){
        Node* root=new Node();
        string s;
        ss>>s;
        root->val=stoi(s);
        ss>>s;
        int l=stoi(s);
        for(int i=0;i<l;i++)
            root->children.push_back(helper(ss));
        return root;
    }
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        //每个node的val后面加一个children的个数
        if(!root) return "";
        string res="";
        res+=(to_string(root->val)+" "+to_string(root->children.size())+" ");
        for(auto i:root->children)
            res+=serialize(i);
        return res;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(data=="") return NULL;
        stringstream ss(data);
        return helper(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
