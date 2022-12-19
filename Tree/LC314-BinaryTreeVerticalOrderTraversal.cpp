class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        int min_index = INT_MAX, max_index = INT_MIN;
        map <TreeNode*, int> store;
        map <int, vector<TreeNode*>> st;
        vector<vector<int>> res;
        queue<TreeNode*> que;
        que.push(root);
        if(root != NULL)
        {
            store[root] = 0;
            st[0].push_back(root);
        }
        while(root!=NULL && !que.empty())
        {
            TreeNode *curr = que.front();
            que.pop();
            if(curr != NULL && curr->left != NULL)
            {
                que.push(curr->left);
                store[curr->left] = store[curr]-1;
                st[store[curr]-1].push_back(curr->left);
                min_index = min(min_index, store[curr->left]);
            }
            if(curr != NULL && curr->right != NULL)
            {
                que.push(curr->right);
                store[curr->right] = store[curr]+1;
                st[store[curr]+1].push_back(curr->right);
                max_index = max(max_index, store[curr->right]);
            }
        }
        for(auto it: st)
        {
           vector<int> temp;
           for(auto i: it.second)
           {
               if(i != NULL)
                temp.push_back(i->val);
           }
           res.push_back(temp);
        } 
        return res;
    }
};
