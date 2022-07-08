class Solution {
public:
    int memo[301][11]={0};
    int dp(vector<int>&nums,int i,int d)
    {
        if(i==nums.size()&&d==0)
            return 0;
        if(d==0||i==nums.size())
            return 1e8;
        if(memo[i][d]!=-1)
            return memo[i][d];
        int cost=nums[i],ans=INT_MAX;
        for(int j=i;j<size(nums);j++)
        {
            cost=max(cost,nums[j]);
            ans=min(ans,cost+dp(nums,j+1,d-1));
        }
        return memo[i][d]=ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) 
    {
        for(int i=0;i<=300;i++)
            for(int j=0;j<=10;j++)memo[i][j]=-1;
        int ans=dp(jobDifficulty,0,d);
        return ans>=1e7?-1:ans;    
    }
};