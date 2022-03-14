class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
    int n=size(nums);
    sort(begin(nums),end(nums));
    return nums[n-k];
    }
};