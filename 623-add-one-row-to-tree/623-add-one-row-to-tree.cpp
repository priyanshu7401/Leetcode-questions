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
    void dfs(TreeNode* root,int val,int depth)
    {
        if(root==NULL)
            return;
        if(depth==2)
        {
            TreeNode* Lnode=new TreeNode(val,root->left,NULL);
            TreeNode* Rnode=new TreeNode(val,NULL,root->right);
            root->left=Lnode;
            root->right=Rnode;
            return;
        }
        dfs(root->left,val,depth-1);
        dfs(root->right,val,depth-1);

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
    if(depth==1)
    {
        TreeNode * node=new TreeNode(val,root,NULL);
        return node;
    }
    dfs(root,val,depth);
    return root;
    }
};