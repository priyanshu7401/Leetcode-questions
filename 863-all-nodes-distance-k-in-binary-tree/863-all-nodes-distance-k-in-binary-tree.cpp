/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,int>mp;
    vector<int>ans;
    int find(TreeNode* root,TreeNode* target)
    {
        if(root==NULL)   return -1;
        if(root==target) 
        {
            mp[root]=0;
            return 1;
        }
        int L=find(root->left,target);
        int R=find(root->right,target);

        if(L>=0) 
        {
            mp[root]=L;
            return L+1;
        }
        if(R>=0) 
        {
            mp[root]=-R;
            return R+1;
        }
        
        return -1;
    }
    void dfs(TreeNode* root,int length,int k)
    {
        if(root==NULL)
            return;
        if(length==k)
        {
            ans.push_back(root->val);
            return;
        }
        dfs(root->left,length+1,k);
        dfs(root->right,length+1,k);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        int depth=find(root,target);
        for(auto [root,length]:mp)
        {
            if(abs(length)==k)
            {
                ans.push_back(root->val);
                continue;
            }
            if(abs(length)>k)
            {
                continue;
            }
            if(length>=0)
               dfs(root->right,abs(length)+1,k);
            if(length<=0)
               dfs(root->left,abs(length)+1,k); 
        }
        return ans;
    }
};