class Solution {
public:
    int dp[1001]={0};
    int dfs(vector<int>&nums,int target)
    {
        if(target==0)
            return 1;
        if(target<0)
            return 0;
        if(dp[target]!=-1)
            return dp[target];
        int ans=0;
        for(int i=0;i<size(nums);i++)
        {
            ans+=dfs(nums,target-nums[i]);
        }
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) 
    {
        for(int i=0;i<1001;i++)
                dp[i]=-1;
        return dfs(nums,target);
    }
};