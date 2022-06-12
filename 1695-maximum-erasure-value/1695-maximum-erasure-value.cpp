class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        unordered_set<int>st;
        int sum=0,j=0,ans=0,n=size(nums);
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            while(j<n&&st.find(nums[i])!=st.end())
            {
                sum-=nums[j];
                st.erase(nums[j++]);
            }
            st.insert(nums[i]);
            ans=max(ans,sum);
        }
        return ans;
    }
};