/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        Node* start1=root;
        while(start1){
            Node* temp1=start1;
            Node *start2=NULL,*temp2=start2;

            while(temp1){
                if(temp1->left){
                    if(!start2){
                        start2=temp2=temp1->left;
                    }
                    else{
                        temp2->next=temp1->left;
                        temp2=temp2->next;
                    }
                }
                if(temp1->right){
                    if(!start2){
                        start2=temp2=temp1->right;
                    }
                    else{
                        temp2->next=temp1->right;
                        temp2=temp2->next;
                    }
                }
                temp1=temp1->next;
            }
            start1=start2;
        }
        return root;
    }
};
