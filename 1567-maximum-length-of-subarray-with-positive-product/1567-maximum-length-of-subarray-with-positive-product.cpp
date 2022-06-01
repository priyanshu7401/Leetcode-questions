class Solution {
public:
    
    int getMaxLen(vector<int>& nums) 
    {
        int n=size(nums),neg=n,last=-1,pro=1,ans=0;
        for(int i=0;i<n;i++)
        {
            pro*=((nums[i]>0)-(nums[i]<0));
            // cout<<pro;
            if(pro>0)
            {
                ans=max(ans,i-last);
            }
            if(pro<0)
            {
                neg=min(i,neg);
                ans=max(ans,i-neg);
            }
            if(pro==0)
            {
                last=i;
                neg=n;
                pro=1;
            }
        }
        return ans;
    }
};