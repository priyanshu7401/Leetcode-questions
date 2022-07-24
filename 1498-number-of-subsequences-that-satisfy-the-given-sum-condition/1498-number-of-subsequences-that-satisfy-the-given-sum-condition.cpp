#define ll long long
class Solution {
public:
    long long mod=1e9+7;
int power(ll x, ll y)
{
    int result = 1;
    while (y > 0) {
      if((y&1)==1) // y is odd
      {
        result=(result*x)%mod;
      }
      x=(x*x)%mod;
      y=y>>1; // y=y/2;
    }
    return result;
}
    int numSubseq(vector<int>& nums, int target) 
    {
        
        sort(begin(nums),end(nums));
        ll ans=0;
        for(int i=0;i<nums.size()&&nums[i]<=target;i++)
        {
            int index=upper_bound(begin(nums),end(nums),target-nums[i])-begin(nums);
            if(index-i-1>=0)
                ans=(ans+power(2,index-i-1))%mod;
        }
        return ans;
    }
    
};