struct mycmp
{
    bool operator()(vector<int>&a,vector<int>&b)
    {
        if(a[0]+a[1]!=b[0]+b[1])
            return a[0]+a[1]>b[0]+b[1];
        return a[0]<b[0];
    }
};
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
    unordered_map<int,vector<int>>map;
    vector<int>ans;
    int maxkey=0;
    for(int i=0;i<nums.size();i++)
    {
        for(int j=0;j<nums[i].size();j++)
        {
            map[i+j].push_back(nums[i][j]);
            maxkey=max(maxkey,i+j);
        }
    }
    for(int i=0;i<=maxkey;i++)
    {
        for(auto j=map[i].rbegin();j!=map[i].rend();j++)
        {
            ans.push_back(*j);
            
        }
    }
        return ans;
    }
};