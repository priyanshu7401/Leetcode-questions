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
    int lnodes=0,rnodes=0;
    int dfs(TreeNode* root,int x)
    {
        if(root==NULL)
            return 0;
        int L=dfs(root->left,x);
        int R=dfs(root->right,x);
        if(root->val==x)
        {
            lnodes=L,rnodes=R;
        }
        return L+R+1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) 
    {
        n=dfs(root,x);
        int remnodes=n-lnodes-rnodes-1;
        int blue=max(remnodes,max(lnodes,rnodes));
        int red=n-blue;
        // cout<<lnodes<<" "<<rnodes<<" "<<red<<" "<<blue<<" "<<remnodes<<endl;
        return red<=blue;
    }
};