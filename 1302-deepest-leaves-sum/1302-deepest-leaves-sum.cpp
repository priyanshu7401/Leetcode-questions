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
    int deepestLeavesSum(TreeNode* root)
    {
        return helper(root).second;
    }
    pair<int,int> helper(TreeNode*root)
    {
        if(root==NULL)
        {
            return {0,0};
        }
        if(root->left==NULL&&root->right==NULL)
        {
            return {1,root->val};
        }
        pair<int,int>left=helper(root->left);
        pair<int,int>right=helper(root->right);
        int lh=left.first;
        int rh=right.first;
        int ls=left.second;
        int rs=right.second;
        if(lh==rh)
        {
            return {lh+1,ls+rs};
        }
        if(lh>rh)
        {
            return {lh+1,ls};
        }
        else
        {
            return {rh+1,rs};
        }
    }
};