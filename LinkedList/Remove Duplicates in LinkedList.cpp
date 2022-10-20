class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        unordered_set <int> st;
        Node *temp = head, *prev = NULL;
        while(temp != NULL)
        {
            if(st.find(temp->data) != st.end())
            {
                prev->next = temp->next;
                delete(temp);
            }
            else
            {
                st.insert(temp->data);
                prev = temp;
            }
            temp = prev->next;
        }
        return head;
    }
};
