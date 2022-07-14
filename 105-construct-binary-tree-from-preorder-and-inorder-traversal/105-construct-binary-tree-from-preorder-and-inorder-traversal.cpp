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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
    return helper(preorder,0,preorder.size()-1,inorder,0,preorder.size()-1);    
    }
    TreeNode* helper(vector<int>& preorder,int psi,int pei, vector<int>& inorder,int isi,int iei)
{
    if(psi>pei||isi>iei)
    {
        return NULL;
    }
    TreeNode* root=new TreeNode(preorder[psi]);
    for(int i=isi;i<=iei;i++)
    {
        if(inorder[i]==preorder[psi])
        {
            root->left=helper(preorder,psi+1,psi+i-isi,inorder,isi,i-1);
            root->right=helper(preorder,psi+i-isi+1,pei,inorder,i+1,iei);
            break;
        }  
    }
    return root;
} 
};