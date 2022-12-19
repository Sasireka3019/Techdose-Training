class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> sortedArr;
        inorder(root, sortedArr);
        int n = sortedArr.size();
        return toBST(sortedArr, 0, n-1);
    }
    void inorder(TreeNode *root, vector<TreeNode*> &sortedArr)
    {
        if(root == NULL)
            return;
        inorder(root->left, sortedArr);
        sortedArr.push_back(root);
        inorder(root->right, sortedArr);
    }
    TreeNode* toBST(vector<TreeNode*> sortedArr, int start, int end)
    {
        if(start > end)
            return NULL;
        int mid = start + (end-start)/2;
        TreeNode *root = sortedArr[mid];
        root->left = toBST(sortedArr, start, mid-1);
        root->right = toBST(sortedArr, mid+1, end);
        return root;
    }
};
