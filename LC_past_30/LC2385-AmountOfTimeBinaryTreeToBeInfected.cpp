/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<int>> adj;
    void makeGraph(TreeNode *root, int parent)
    {
        if(!root)
            return;
        if(parent != -1)
        {
            adj[parent].push_back(root->val);
            adj[root->val].push_back(parent);
        }
        makeGraph(root->left, root->val);
        makeGraph(root->right, root->val);
    }
    int amountOfTime(TreeNode* root, int start) {
        makeGraph(root, -1);
        queue<int> q;
        int time = 0;
        q.push(start);
        vector<bool> visited(10000001, false);
        visited[start] = true;
        while(!q.empty())
        {
            int n = q.size();
            time++;
            while(n--)
            {
                int curr = q.front();
                q.pop();
                for(auto i : adj[curr])
                {
                    if(visited[i] == false)
                    {    
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
        return time-1;
    }
};
