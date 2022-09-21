class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int even=0,n=size(nums);
        for(int i=0;i<size(nums);i++)
        {
            if(nums[i]%2==0)
                even+=nums[i];
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++)
        {
            int ind=queries[i][1];
            int val=queries[i][0];
            if(nums[ind]%2==0&&val%2==0)
            {
                even+=val;
            }
            else if(nums[ind]%2 && val%2)
            {
                even+=nums[ind]+val;
            }
            else if(nums[ind]%2==0 &&val%2)
            {
                even-=nums[ind];
            }
            ans.push_back(even);
            nums[ind]+=val;
        }
        return ans;
    }
};