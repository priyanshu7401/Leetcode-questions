class Solution {
public:
    int dp(vector<int>&nums,int i,int last,int j,vector<vector<vector<int>>>&memo)
    {
    if(i==nums.size())
        return 0;
    if(memo[i][j][last==1]!=-1)
        return memo[i][j][last==1];
    int ans2=0;
    int ans1=dp(nums,i+1,last,j,memo);
    if(nums[i]!=nums[j])
    {
    int curr=(nums[i]-nums[j])/abs(nums[i]-nums[j]);
    if(curr!=last)
    {
        ans2=1+dp(nums,i+1,curr,i,memo);
    }
    }
    return memo[i][j][last==1]=max(ans1,ans2);
    }
    int wiggleMaxLength(vector<int>& nums) 
    {
        if(size(nums)==0)
        return 0;
        vector<vector<vector<int>>>memo(size(nums),vector<vector<int>>(size(nums),vector<int>(2,-1)));
        return max(dp(nums,0,-1,0,memo),dp(nums,0,1,0,memo))+1;    
    }
};