/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* merge2lists(ListNode* l1, ListNode* l2){
        ListNode dummy(INT_MIN);
        ListNode *p=&dummy;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<l2->val){
                p->next=l1;
                l1=l1->next;
            }
            else{
                p->next=l2;
                l2=l2->next;
            }
            p=p->next;
        }
        if(l1!=NULL) p->next=l1;
        if(l2!=NULL) p->next=l2;
        return dummy.next;
    }
    void helper(vector<ListNode*>::iterator l, vector<ListNode*>::iterator r){
        if(r-l==1) return;
        helper(l,l+(r-l)/2);
        helper(l+(r-l)/2,r);
        *l=merge2lists(*l,*(l+(r-l)/2));
        return;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==0) return NULL;
        helper(lists.begin(),lists.end());
        return lists[0];
    }
};
