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
    int ans=0;
    int helper(TreeNode* root,int p,int gp)
    {
        if(root==NULL)
            return 0;
        return helper(root->left,root->val,p)+ helper(root->right,root->val,p)+(gp%2==0?root->val:0);
    }
    int sumEvenGrandparent(TreeNode* root) 
    {
        return helper(root,1,1);
    }
};






    // int sumEvenGrandparent(TreeNode* root) 
    // {
    // if(root==NULL)
    // {
    //     return 0;
    // }
    // int ans=0;
    // if(root->val%2==0)
    // {
    //     if(root->left!=NULL&&root->left->left!=NULL)
    //          ans=ans+root->left->left->val;
    //     if(root->left!=NULL&&root->left->right!=NULL)
    //          ans=ans+root->left->right->val;
    //     if(root->right!=NULL&&root->right->left!=NULL)
    //          ans=ans+root->right->left->val;
    //     if(root->right!=NULL&&root->right->right!=NULL)
    //          ans=ans+root->right->right->val;
    // }
    // ans=ans+sumEvenGrandparent(root->left) +sumEvenGrandparent(root->right);
    // return ans;
    // }