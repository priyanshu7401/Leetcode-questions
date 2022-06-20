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
    vector<int>temp;
    void dfs(TreeNode* root, vector<int>&temp)
    {
        if(root==NULL)return;  
        temp[root->val]++;
        if(root->left==NULL && root->right==NULL)
        {
            int countodd=0;
            for(int i=1;i<=9;i++)
            {
                // cout<<temp[i]<<" ";
                countodd+=temp[i]%2;
            }
            // cout<<endl;
            ans+=(countodd<=1);
        }
        dfs(root->left,temp);
        dfs(root->right,temp);
        temp[root->val]--;
        
        return;
    }
    int pseudoPalindromicPaths (TreeNode* root) 
    {
    temp.resize(10,0);
    dfs(root,temp);
    return ans;
    }
};