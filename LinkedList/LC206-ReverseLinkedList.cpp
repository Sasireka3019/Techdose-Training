//Iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *prev = NULL, *next;
        if(!head)
            return NULL;
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
//Recursive
class Solution {
public:
    ListNode* reverse(ListNode *prev, ListNode *curr)
    {
        ListNode *head;
        if(!curr)
            return NULL;
        if(!curr->next)
        {
            head = curr;
            curr->next = prev;
            return head;
        }
        reverse(curr, curr->next);
        curr->next = prev;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(NULL, head);
    }
};
