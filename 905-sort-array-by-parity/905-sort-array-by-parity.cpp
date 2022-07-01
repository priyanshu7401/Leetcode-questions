class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        int n=size(nums);
       vector<int>ans(n,0);
        int start=0,end=n-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)ans[start++]=nums[i];
            else ans[end--]=nums[i];
        }
        return ans;
    }
};