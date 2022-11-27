class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return helper(root->left, root->right);
    }
    bool helper(TreeNode* l, TreeNode* r)
    {
        if(!l && !r)
            return true;
        else if(!l || !r)
            return false;
        if(l->val != r->val)
            return false;
        return helper(l->left, r->right) && helper(l->right, r->left);
    }
};
