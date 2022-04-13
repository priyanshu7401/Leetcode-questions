class Solution {
public:
    int memo[201][201]={[0 ... 200][0 ... 200]=-1};
    int dp(vector<int>&nums,int i,int k)
    {
        if(i==size(nums))return 0;
        if(k==-1)return 2e9;
        
        int ans=2e9,sum=0,maxi=nums[i];
        if(memo[i][k]!=-1)
            return memo[i][k];
        for(int j=i;j<size(nums);j++)
        {
            maxi=max(maxi,nums[j]);
            sum+=nums[j];
            int wasted=maxi*(j-i+1)-sum;
            ans=min(ans,dp(nums,j+1,k-1)+wasted);
        }
        return memo[i][k]=ans;
    }
    int minSpaceWastedKResizing(vector<int>& nums, int k) 
    {
        return dp(nums,0,k);    
    }
};