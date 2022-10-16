class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk) 
    {
        long long jmin=-1,jmax=-1,ans=0,jbad=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<mink||nums[i]>maxk)jbad=i,jmin=i,jmax=i;
            
            if(nums[i]==mink)jmin=i;
            
            if(nums[i]==maxk)jmax=i;
            
            ans+=(min(jmax,jmin)-jbad);
            
        }
        return ans;
    }
};