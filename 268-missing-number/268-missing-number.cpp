class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
    sort(begin(nums),end(nums));
    for(int i=0;i<size(nums);i++)
    {
        if(i!=nums[i])
            return i;
    }
        return nums.size();
    }
};