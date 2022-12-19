class Solution {
public:
    int n, index = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        n = preorder.size();
        return helper(preorder, INT_MIN, INT_MAX);
    }
    TreeNode* helper(vector<int> preorder, int lower, int upper)
    {
        if(index == n)
            return NULL;
        int val = preorder[index];
        if(val < lower || val > upper)
            return NULL;
        index += 1;
        TreeNode *root = new TreeNode(val);
        root->left = helper(preorder, lower, val);
        root->right = helper(preorder, val, upper);
        return root;
    }
};
