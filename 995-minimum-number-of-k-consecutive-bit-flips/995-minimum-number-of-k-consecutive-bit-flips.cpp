class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) 
    {
        int ans=0,n=nums.size(),count=0;
        for(int i=0;i<n;i++)
        {
            if(i>=k)
                count-=(nums[i-k]==-1);
            
            if(nums[i]^(count%2)==0)
            {
                if(i+k<=n)
                {
                    ans++;
                    count++;
                    nums[i]=-1;
                }
                else
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};