class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        TreeNode* node = root;
        while(node != NULL)
        {
            if(node->left != NULL)
            {
                TreeNode *rightmost = node->left;
                while(rightmost != NULL && rightmost->right != NULL)
                {
                    rightmost = rightmost->right;
                }
                rightmost->right = node->right;
                node->right = node->left;
                node->left = NULL;
            }
            node = node->right;
        }
        return;
    }
};
