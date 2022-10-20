class Solution
{
    public:
    int removeLoop(Node* head)
    {
        Node *slow = head, *fast = head;
        if(head == NULL || head->next == NULL)
            return;
        while(slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        if(slow != fast)
            return;
        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow->data;
    }
};
