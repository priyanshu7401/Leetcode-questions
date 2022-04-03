class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int i=size(nums)-1;
        while(i>0&&nums[i]<=nums[i-1])i--;
        if(i)
        {
        int j=size(nums)-1;
        for(;j>=i&&nums[j]<=nums[i-1];j--);
        swap(nums[i-1],nums[j]);
        }
        reverse(begin(nums)+i,end(nums));
    }
};