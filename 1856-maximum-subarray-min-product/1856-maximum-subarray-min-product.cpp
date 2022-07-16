class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) 
    {
        
        int n=size(nums);
        vector<int>right(n,n),left(n,-1);
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty()&&nums[s.top()]>nums[i])
            {
                right[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty()&&nums[s.top()]>nums[i])
            {
                left[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }   
        vector<long long>prefix(n+1,0);
        for(int i=0;i<n;i++)
        {
          prefix[i+1]=prefix[i]+nums[i];
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,1LL*nums[i]*(prefix[right[i]]-prefix[left[i]+1]));
        }
        int mod=1e9+7;
        return ans%mod;
    }
};