/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
    if(root==NULL)
        return {};
    vector<vector<int>>ans;
    queue<Node*>q;
    q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int>temp;
            for(int i=0;i<n;i++)
            {
                auto x=q.front();
                temp.push_back(x->val);
                q.pop();
                for(int j=0;j<x->children.size();j++)
                {
                    if(x->children[j])
                        q.push(x->children[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};