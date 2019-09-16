/*
Given a singly linked list, determine if it is a palindrome.

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
*/

bool isPalindrome(ListNode* head) {
    //1 2 2 1
    //1 2 1
    if(!head) return true;

    ListNode* slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    //reverse fast to end;
    ListNode* head2=slow;
    while(slow->next){
        ListNode* temp=slow->next->next;
        slow->next->next=head2;
        head2=slow->next;
        slow->next=temp;
    }
    while(head2){
        if(head->val==head2->val){
            head=head->next;
            head2=head2->next;
        }
        else return false;
    }
    return true;
}
