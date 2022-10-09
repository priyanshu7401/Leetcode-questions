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
    unordered_map<int,int>map;
    bool findTarget(TreeNode* root, int k) 
    {
        if(!root)
            return false;
        bool ans=findTarget(root->left,k)||findTarget(root->right,k);
        if(map.count(k-(root->val)))
            return true;
        map[root->val]++;
        return ans;
    }
};