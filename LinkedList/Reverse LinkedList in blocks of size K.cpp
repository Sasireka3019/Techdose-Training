/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    static int count(ListNode* head)
    {
        int cnt = 0;
        while(head != NULL)
        {
            head = head->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(count(head) < k)
            return head;
        ListNode *curr = head, *prev = NULL, *next = NULL;
        for(int i=0; i<k; i++)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};
