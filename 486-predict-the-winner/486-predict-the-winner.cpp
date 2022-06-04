class Solution {
public:
    int dp(vector<int>&nums,int i,int j)
    {
        if(j<i)
            return 0;
        int ans=max(nums[i]-dp(nums,i+1,j),nums[j]-dp(nums,i,j-1));
        return ans;
    }
    bool PredictTheWinner(vector<int>& nums) 
    {
        int n=size(nums);
        // int ans=dp(nums,0,n-1);
        // cout<<ans<<endl;
        return dp(nums,0,n-1)>=0;    
    }
};