class Solution {
public:
//     int dp(vector<int>&nums,int i,int j)
//     {
        
//     }
    int minOperations(vector<int>& nums, int x) 
    {
        unordered_map<int,int>map;
        int sum=0,ans=INT_MAX,n=size(nums);
        for(int i=0;i<size(nums)&&x-sum>=0;i++)
        {
            sum+=nums[i];
            map[sum]=i+1;
            if(x==sum)
                ans=i+1;
        }
        sum=0;
        for(int j=n-1;j>=0;j--)
        {
            sum+=nums[j];
            if(map.count(x-sum)&&n-j+map[x-sum]<=n)
            {
                ans=min(ans,n-j+map[x-sum]);
            }
            if(x==sum)
            {
                ans=min(ans,n-j);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};