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
    pair<int,TreeNode*>  dfs(TreeNode* root)
    {
        if(root==NULL)
            return {0,NULL};
        auto L=dfs(root->left);
        auto R=dfs(root->right);
        pair<int,TreeNode*>ans;
        
        ans.first=max(L.first,R.first)+1;
        if(L.first==R.first)
            ans.second=root;
        else
            ans.second=L.first>R.first?L.second:R.second;
        return ans;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
        auto [depth,ans]=dfs(root);
        return ans;
    }
};