class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold)
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
        
        for(int i=0;i<n;i++)
        {
            int len=(right[i]-left[i]-1);
            if(1LL*nums[i]*len>threshold)
                return len;
        }
        return -1;
    }
};
