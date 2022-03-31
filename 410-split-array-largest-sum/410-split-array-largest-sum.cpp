# define sum(arr)  accumulate(begin(arr),end(arr),1LL*0)
# define maximum(arr)  *max_element(begin(arr),end(arr))
class Solution {
public:
    int splitArray(vector<int>& nums, int m) 
    {
        int lo=maximum(nums),hi=sum(nums);
        int n=size(nums);
        while(lo<hi)
        {
            int mid=(lo+hi)/2;
            int sum=0,count=1;
            // int bag=0;
            for(int i=0;i<n;i++)
            {
                if(sum+nums[i]>mid)
                {
                    // bag=max(bag,sum);
                    count++;
                    sum=0;
                }
                sum+=nums[i];
            }
                if(count>m)
                {
                    lo=mid+1;
                }
                else
                    hi=mid;
                
            
        }
        return lo;
    }
};