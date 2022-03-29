class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
    int slow=nums[0];
    int fast=nums[0];
    int entry=nums[0];
    while(1)
    {
        slow=nums[slow];
        fast=nums[nums[fast]];
        if(slow==fast)
        {
            while(entry!=slow)
            {
                slow=nums[slow];
                entry=nums[entry];
            }
            return entry;
        }
    }
    
    }
};