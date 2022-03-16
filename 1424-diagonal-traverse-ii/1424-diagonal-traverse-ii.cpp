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
    priority_queue<vector<int>,vector<vector<int>>,mycmp>pq;
    vector<int>ans;
    for(int i=0;i<nums.size();i++)
    {
        pq.push({i,0});
    }
    while(!pq.empty())
    {
        auto temp=pq.top();
        pq.pop();
        ans.push_back(nums[temp[0]][temp[1]++]);
        if(temp[1]!=nums[temp[0]].size())
            pq.push(temp);
    }
        return ans;
    }
};