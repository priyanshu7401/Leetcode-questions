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
    vector<TreeNode*>sorted;
    void inorder(TreeNode*root)
    {
        if(root==NULL)
            return;        
        inorder(root->left);
        sorted.push_back(root);
        inorder(root->right);      
        return;
    }
    TreeNode* balanceBST(TreeNode* root) 
    {
        inorder(root);
        return dfs(0,size(sorted)-1);
    }
    TreeNode* dfs(int left,int right)
    {
        if(left>right)
            return NULL;
        int mid=(left+right)/2;
        TreeNode* root=sorted[mid];
        root->left=dfs(left,mid-1);
        root->right=dfs(mid+1,right);
        return root;
    }
};