/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //99+1=100
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
     //每次carry记录是否进位， 如果l1 l2 carry不为NULL，向下一位生成，
     //时刻注意，l1，l2是否已经是NULL
        ListNode dummyHead(0);
        ListNode *current=&dummyHead;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry!=0)
        {
            int x=(l1!=NULL)? l1->val:0;
            int y=(l2!=NULL)? l2->val:0;
            int digit=carry+x+y;
            carry=digit/10;
            current->next=new ListNode(digit%10);
            current=current->next;
            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;
        }
        return dummyHead.next;
    }
};
