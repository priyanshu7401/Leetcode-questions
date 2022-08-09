#define ll long long
class Solution {
public:
    unordered_map<int,int>map;
    ll mod=1e9+7;
    vector<int>memo;
    ll dp(vector<int>&nums,int root)
    {
        if(memo[root]!=-1)
            return memo[root];
        ll ans=1;
        for(int i=0;i<size(nums);i++)
        {
            if(nums[root]%nums[i]==0 && map.count(nums[root]/nums[i]))
            {
                ans=(ans+(dp(nums,i)*dp(nums,map[nums[root]/nums[i]])))%mod;
            }
        }
        return memo[root]=ans;
    }
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        for(int i=0;i<size(arr);i++)
            map[arr[i]]=i;
        memo.resize(1001,-1);
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            ans=(ans+dp(arr,i))%mod;
        }
        return ans;
    }
};