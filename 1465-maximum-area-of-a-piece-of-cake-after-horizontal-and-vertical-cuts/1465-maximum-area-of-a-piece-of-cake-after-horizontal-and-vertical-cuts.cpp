class Solution {
public:
    int mod=1e9+7;
    int maxdiff(vector<int>&nums,int length)
    {
        sort(begin(nums),end(nums));
        int prev=0;
        int ans=0;
        for(int i=0;i<size(nums);i++)
        {
            ans=max(ans,nums[i]-prev);
            prev=nums[i];
        }
        return max(ans,length-prev);
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) 
    {
        return (1LL*maxdiff(horizontalCuts,h)*maxdiff(verticalCuts,w))%mod;
    }
};