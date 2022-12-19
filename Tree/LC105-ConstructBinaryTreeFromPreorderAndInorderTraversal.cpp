class Solution {
public:
    map<int, int> hashmap;
    int preorderIndex = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0; i<n; i++)
        {
            hashmap[inorder[i]] = i;
        }
        return helper(preorder, 0, preorder.size()-1);
    }
    TreeNode* helper(vector<int> preorder, int start, int end)
    {
        if(start > end)
            return NULL;
        int rootVal = preorder[preorderIndex++];
        TreeNode *root = new TreeNode(rootVal);
        root->left = helper(preorder, start, hashmap[rootVal]-1);
        root->right = helper(preorder, hashmap[rootVal]+1, end);
        return root;
    }
};
