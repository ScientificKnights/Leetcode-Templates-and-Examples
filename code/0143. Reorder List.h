/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Given 1->2->3->4, reorder it to 1->4->2->3.

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
private:
    ListNode* reverse(ListNode* input){
        ListNode *dummy1=new ListNode(0),*dummy2=new ListNode(0),*temp;
        dummy1->next=input;
        while(dummy1->next){
            temp=dummy2->next;
            dummy2->next=dummy1->next;
            dummy1->next=dummy1->next->next;
            dummy2->next->next=temp;
        }
        return dummy2->next;
    }
    ListNode* merge(ListNode* l1,ListNode*l2){
        ListNode *temp1=l1,*temp2=l2, *temp3;
        ListNode *dummy=new ListNode(0);
        temp3=dummy;
        while(temp1){
            temp3->next=temp1;
            temp1=temp1->next;
            temp3=temp3->next;
            if(temp2){      //l1比l2 最多多一个
                temp3->next=temp2;
                temp2=temp2->next;
                temp3=temp3->next;
            }
        }
        temp3->next=NULL;
        return dummy->next;
    }
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode* slow=head, *fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        // slow 1,2,3,4停在2；
        // 1，2，3，4，5停在3；cut slow 后面的
        ListNode* mid=slow->next;
        slow->next=NULL;
        mid=reverse(mid);
        head=merge(head,mid);
        return;
    }
};
