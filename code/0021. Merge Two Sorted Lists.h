/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
    ListNode dummy(INT_MIN);
    ListNode *p=&dummy;
    while(l1!=NULL && l2!=NULL)
    {
        if(l1->val<l2->val)
        {
            p->next=l1;
            l1=l1->next;
        }
        else
        {
            p->next=l2;
            l2=l2->next;
        }
        p=p->next;
    }
    if(l1!=NULL) p->next=l1;
    if(l2!=NULL) p->next=l2;
    return dummy.next;
}
