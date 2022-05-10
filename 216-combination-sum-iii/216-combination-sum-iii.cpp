class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int k,int n,vector<int>&temp,int start)
    {
        if(n==0&&k==0)
        {
            ans.push_back(temp);
            return;
        }
        if(n<0||k==0||start>9)
            return;
        dfs(k,n,temp,start+1);
        temp.push_back(start);
        dfs(k-1,n-start,temp,start+1);
        temp.pop_back();

    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
    if(n>45)
        return {};
    vector<int>temp;
    dfs(k,n,temp,1);
    return ans;
    }
};