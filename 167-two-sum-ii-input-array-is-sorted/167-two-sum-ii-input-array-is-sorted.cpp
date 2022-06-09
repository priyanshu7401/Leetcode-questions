class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
    int lo=0;
    int hi=size(nums)-1;
    while(lo<hi)
    {
        if(nums[lo]+nums[hi]==target)
            return {lo+1,hi+1};
        if(nums[lo]+nums[hi]>target)
            hi--;
        else
            lo++;
    }
        return {-1,-1};
    }
};