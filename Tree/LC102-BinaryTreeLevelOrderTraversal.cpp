class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> res;
        while(root != NULL && !que.empty())
        {
            int len = que.size();
            vector<int> temp;
            for(int i=0; i<len; i++)
            {
                TreeNode *curr = que.front();
                que.pop();
                temp.push_back(curr->val);
                if(curr != NULL && curr->left != NULL)
                    que.push(curr->left);
                if(curr != NULL && curr->right != NULL)
                    que.push(curr->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};
