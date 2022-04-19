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
    TreeNode*x=NULL;
    TreeNode*y=NULL;
    TreeNode*predecessor=NULL;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;

        inorder(root->left);
        if(predecessor&&predecessor->val>root->val)
        {
            if(x==NULL)
            {
                x=predecessor;
            }
            y=root;
        }
        predecessor=root;
        inorder(root->right);
        return;
    }
    void recoverTree(TreeNode* root) 
    {   
        inorder(root);
        swap(x->val,y->val);
    }
};


