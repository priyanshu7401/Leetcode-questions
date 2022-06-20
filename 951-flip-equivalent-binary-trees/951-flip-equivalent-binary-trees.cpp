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
    bool dfs(TreeNode *root1,TreeNode* root2)
    {
        if(root1==NULL&&root2==NULL)
            return true;
        if(!root1||!root2||root1->val!=root2->val)
            return false;
        bool ans1=dfs(root1->left,root2->left)&dfs(root1->right,root2->right);
        bool ans2=dfs(root1->left,root2->right)&dfs(root1->right,root2->left);    
        return ans1||ans2;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) 
    {
        return dfs(root1,root2);    
    }
};