class Solution {
public:
    int maxSum = INT_MIN;
    int maxPath(TreeNode* root)
    {
        if(!root)
            return 0;
        int l = max(0, maxPath(root->left));
        int r = max(0, maxPath(root->right));
        maxSum = max(maxSum, root->val+l+r);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) 
    {
        maxPath(root);
        return maxSum;
    }
};
