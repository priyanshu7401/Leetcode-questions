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
    // TreeNode* ans=NULL;
    pair<TreeNode*,int> dfs(TreeNode* root)
    {
       if(root==NULL)
           return {NULL,0};
        auto [left_lca,L]=dfs(root->left);
        auto [right_lca,R]=dfs(root->right);
        pair<TreeNode*,int> ans;
        if(L==R)
        {
           ans.first=root;
        }
        else
            ans.first=(L>R)?left_lca:right_lca;
        ans.second=max(L,R)+1;
        return ans;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
      auto ans=dfs(root);
      return ans.first;
    }
};