class Solution {
public:
    Node* first = NULL;
    Node* last = NULL;
    Node* treeToDoublyList(Node* root) {
        if(root == NULL)
            return NULL;
        helper(root);
        last->right = first;
        first->left = last;
        return first;
    }
    void helper(Node* node)
    {
        if(node)
        {
            helper(node->left);
            if(last)
            {
                last->right = node;
                node->left = last;
            }
            else
                first = node;
            last = node;
            helper(node->right);
        }
    }
};
