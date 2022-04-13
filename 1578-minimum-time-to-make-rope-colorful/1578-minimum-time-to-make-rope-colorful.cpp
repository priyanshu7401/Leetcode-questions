class Solution {
public:
    int minCost(string colors, vector<int>& cost) 
    {
    int ans=0,n=size(colors);
    for(int i=1;i<n;i++)
    {
        if(colors[i]==colors[i-1])
        {
            ans+=min(cost[i],cost[i-1]);
            cost[i]=max(cost[i],cost[i-1]);
        }
    }
        return ans;
    }
};