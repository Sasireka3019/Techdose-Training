class Solution {
public:
    int xdepth, ydepth, xpar, ypar;
    void depth(TreeNode* root, int x, int y, int dep, int par)
    {
        if(root == NULL)
            return;
        if(root->val == x)
        {
            xdepth = dep;
            xpar = par;
            return;
        }
        if(root->val == y)
        {
            ydepth = dep;
            ypar = par;
            return;
        }
        depth(root->left, x, y, dep+1, root->val);
        depth(root->right, x, y, dep+1, root->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x || root->val == y)
            return false;
        depth(root, x, y, 0, 0);
        if(xdepth == ydepth && xpar != ypar)
            return true;
        return false;
    }
};
