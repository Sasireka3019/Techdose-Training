class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> curr(size);
            for(int i=0; i<size; i++)
            {
                TreeNode* t = q.front();
                q.pop();
                if(level%2 == 1)
                    curr[size-i-1] = t->val;
                else
                    curr[i] = t->val;
                if(t != NULL && t->left != NULL)
                q.push(t->left);
                if(t != NULL && t->right != NULL)
                q.push(t->right);
            }
            level += 1;
            result.push_back(curr);
        }
        return result;
    }
};
