class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        int ans=0;
        vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size(),0));
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                    dp[i][j]=((i>0&&j>0)?dp[i-1][j-1]:0)+1;
                ans=max(dp[i][j],ans);
            }
        }
        return ans;
    }
};