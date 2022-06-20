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
    int moves=0;
    int dfs(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int L=dfs(root->left);
        int R=dfs(root->right);
        moves+=abs(L+R+root->val-1);
        return L+R+root->val-1;
        
    }
    int distributeCoins(TreeNode* root) 
    {
        int dfs_ans=dfs(root);
        return moves;
    }
};