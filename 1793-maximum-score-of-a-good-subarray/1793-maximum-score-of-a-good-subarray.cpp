class Solution {
public:
    int maximumScore(vector<int>& nums, int k) 
    {
        int i=k,j=k,ans=nums[k],n=size(nums),mini=nums[k];
        while(i>=1||j+1<n)
        {
            int num_init=(i-1>=0)?nums[i-1]:INT_MIN;
            int num_last=(j+1)<n?nums[j+1]:INT_MIN;
            if(num_init>num_last)
            {
                mini=min(num_init,mini);
                i--;
            }
            else
            {
                mini=min(num_last,mini);
                j++;        
            }
            ans=max(ans,mini*(j-i+1));     
        }
        return ans;
    }
};