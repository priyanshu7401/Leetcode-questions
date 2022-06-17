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
    int minCameraCover(TreeNode* root) {
        vector<int>ans=helper(root);
        return min(ans[1],ans[2]);
    }
    vector<int>helper(TreeNode*root)
    {
        if(root==NULL)
        {
            return {0,0,999999};
        }
        vector<int> L=helper(root->left);
        vector<int> R=helper(root->right);
        int d0=L[1]+R[1];
        int d1=min(L[2]+min(R[1],R[2]),R[2]+min(L[1],L[2]));
        int d2=1+min(L[0],min(L[1],L[2]))+min(R[0],min(R[1],R[2]));
        return {d0,d1,d2};
    }
};