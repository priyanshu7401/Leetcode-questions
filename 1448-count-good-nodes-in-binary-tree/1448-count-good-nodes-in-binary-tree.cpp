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
    int goodNodes(TreeNode* root,int X=-10000) 
    {
    if(root==NULL)
    {
        return 0;
    }
    bool ans=0;
    if(root->val>=X)
    {
        ans=1;
        X=root->val;
    }
    int left=goodNodes(root->left,X);
    int right=goodNodes(root->right,X);
    return left+right+ans;
    }
};