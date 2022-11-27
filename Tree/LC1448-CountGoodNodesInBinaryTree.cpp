class Solution {
public:
    int cnt = 0;
    void preOrder(TreeNode* root, int maxi)
    {
        if(root == NULL)
            return;
        if(root->val >= maxi)
        {
            cnt += 1;
            maxi = root->val;
        }
        preOrder(root->left, maxi);
        preOrder(root->right, maxi);
    }
    int goodNodes(TreeNode* root) 
    {
        preOrder(root, INT_MIN);
        return cnt;
    }
};
