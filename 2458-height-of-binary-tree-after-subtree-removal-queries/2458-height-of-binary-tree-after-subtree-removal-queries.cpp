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

    int dp[100001]={0};
    int maxi1=0,maxi2=0;
    void dfs(TreeNode *root,int height=0)
    {
        if(root==NULL)
            return;
        dp[root->val]=max(maxi2,dp[root->val]);  
        maxi2=max(maxi2,height);      
        dfs(root->left,height+1);
        dfs(root->right,height+1);          
    }
    
    void reversedfs(TreeNode *root,int height=0)
    {
        
        if(root==NULL)
        return ;        
        dp[root->val]=max(maxi1,dp[root->val]);
        maxi1=max(maxi1,height);
        reversedfs(root->right,height+1);
        reversedfs(root->left,height+1); 
        return;       
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) 
    {
        vector<int>ans;
        dfs(root,0);
        reversedfs(root,0);
          
        for(int i=0;i<queries.size();i++)
        {
            ans.push_back(dp[queries[i]]);
        }
        return ans;
    }
};