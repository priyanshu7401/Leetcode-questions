class Solution {
public:
    int maxOperations(vector<int>& nums, int k) 
    {
        unordered_map<int,int>map;
        int count=0;
        for(int i=0;i<size(nums);i++)
        {
            if(map[k-nums[i]]>0)
                map[k-nums[i]]--,count++;
            else
                map[nums[i]]++;
        }
        return count;
    }
};