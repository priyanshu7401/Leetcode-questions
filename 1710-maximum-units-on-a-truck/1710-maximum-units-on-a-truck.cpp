class Solution {
public:
    int maximumUnits(vector<vector<int>>& nums, int truckSize) 
    {
        sort(begin(nums),end(nums),[&](vector<int>&a,vector<int>&b){return a[1]>b[1];});
        int ans=0;
        for(int i=0;i<size(nums);i++)
        {
            ans+=min(nums[i][0],truckSize)*nums[i][1];
            truckSize-=min(nums[i][0],truckSize);
            if(truckSize==0)
                return ans;
        }
        return ans;
        
    }
};