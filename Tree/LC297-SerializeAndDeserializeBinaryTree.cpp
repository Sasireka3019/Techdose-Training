class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root)
            return "NULL,";
        return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
    }
    TreeNode* helper(queue <string> &que)
    {
        string s = que.front();
        que.pop();
        if(s == "NULL")
            return NULL;
        TreeNode* root = new TreeNode(stoi(s));
        root->left = helper(que);
        root->right = helper(que);
        return root;
    }
    TreeNode* deserialize(string data)
    {
        string s = "";
        queue <string> que;
        for(char c: data)
        {
            if(c == ',')
            {
                que.push(s);
                s = "";
            }
            else
                s += c;
        }
        if(s.size() > 0)
           que.push(s);
        return helper(que);
    }
};
