class Solution {
public:
    
    int getMaxLen(vector<int>& nums) 
    {
        int n=size(nums),neg=0,pos=0,ans=0;
        for(int i=0;i<n;i++)
        {
            pos++;
            if(neg!=0) neg++;
            if(nums[i]<0)
            {
               swap(pos,neg); 
            }
            if(!nums[i])
            {
                pos=0,neg=0;
            }
            ans=max(ans,pos);
        }
        return ans;
    }
};