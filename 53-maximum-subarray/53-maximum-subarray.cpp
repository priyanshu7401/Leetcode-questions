class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
    int sum=0,ans=INT_MIN,mini=0;
    for(int i=0;i<size(nums);i++)
    {
        sum+=nums[i];
        ans=max(ans,sum-mini);
        mini=min(mini,sum);
    }
        return ans;
    }
};