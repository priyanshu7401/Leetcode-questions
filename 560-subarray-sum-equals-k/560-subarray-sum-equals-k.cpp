class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int>map;
        int count=0;
        map[0]=1;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            count+=map[sum-k];
            map[sum]+=1;
        }
        return count;
    }
};