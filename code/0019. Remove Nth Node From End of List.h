/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:
Could you do this in one pass?
*/

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next=head;
    ListNode* first=&dummy;
    for(int i=0;i<n;i++)
        first=first->next;
    ListNode* second=&dummy;
    while(first->next!=NULL){
        first=first->next;
        second=second->next;
    }
    second->next=second->next->next;
    return dummy.next;
}
