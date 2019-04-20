/*
Convert a BST to a sorted circular doubly-linked list in-place. Think of the left and right pointers as synonymous to the previous 
and next pointers in a doubly-linked list.

Let's take the following BST as an example, it may help you understand the problem better:
We want to transform this BST into a circular doubly linked list. Each node in a doubly linked list has a predecessor and successor. 
For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is 
the first element.

The figure below shows the circular doubly linked list for the BST above. The "head" symbol means the node it points to is 
the smallest element of the linked list.
 
Specifically, we want to do the transformation in place. After the transformation, 
the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. 
We should return the pointer to the first element of the linked list.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
private:
    void helper(Node* root,Node* &first, Node* &last){
        
        Node *l=NULL, *r=NULL;
        if(root->left)  helper(root->left,first,l);
        if(l){
            l->right=root;
            root->left=l;
        }
        else first=root;
        
        if(root->right) helper(root->right,r,last);
        if(r){
            r->left=root;
            root->right=r;
        }
        else
            last=root;
        return;
    }
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        Node *first=NULL,*last=NULL;
        helper(root,first,last);
        first->left=last;
        last->right=first;
        return first;
    }
};
