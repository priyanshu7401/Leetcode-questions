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
    vector<TreeNode*>ans;
    TreeNode*dfs(TreeNode*root,unordered_set<int>& set)
    {
        if(root==NULL)
            return NULL;
        root->left=dfs(root->left,set);
        root->right=dfs(root->right,set);

        if(set.find(root->val)!=set.end())
        {
            if(root->left)ans.push_back(root->left);
            if(root->right)ans.push_back(root->right);
            delete(root);
            return NULL;
        }

        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
    unordered_set<int>set({begin(to_delete),end(to_delete)});
    TreeNode*new_root=dfs(root,set);
    if(new_root)ans.push_back(new_root);
    return ans;
    }
};