struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
    result->val = 0;
    struct ListNode *trav = result;
    int sum = 0;
    while(sum || l1 || l2)
    {
        if(l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = (sum%10);
        temp->next = NULL;
        trav->next = temp;
        trav = trav->next;
        sum /= 10;
    }
    return result->next;
}
