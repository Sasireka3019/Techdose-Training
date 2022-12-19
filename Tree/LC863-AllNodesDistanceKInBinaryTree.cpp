/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map <TreeNode*, vector<TreeNode*>> adj;
        vector<int> res;
        queue <TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode* node = que.front();
            que.pop();
            if(node->right != NULL)
            {
                que.push(node->right);
                adj[node].push_back(node->right);
                adj[node->right].push_back(node);
            }
            if(node->left != NULL)
            {
                que.push(node->left);
                adj[node].push_back(node->left);
                adj[node->left].push_back(node);
            }
        }
        queue <TreeNode*> finder;
        finder.push(target);
        int distance = 0;
        map<TreeNode*, int> visited;
        while(!finder.empty() && distance <= k)
        {
            int len = finder.size();
            for(int i=0; i<len; i++)
            {
                TreeNode *curr = finder.front();
                visited[curr] = true;
                finder.pop();
                if(distance == k)
                    res.push_back(curr->val);
                for(auto neighbor : adj[curr])
                {
                    if(visited.find(neighbor) == visited.end())
                    {
                        visited[neighbor] = 1;
                        finder.push(neighbor);
                    }
                }
            }
            distance += 1;
        }
        return res;   
    }
};
