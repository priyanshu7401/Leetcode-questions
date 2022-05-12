class Solution {
public:
    vector<vector<int>>permutations;
    void   backtrack(vector<int>&nums,vector<int>p)
    {
        if(size(nums)==0)
           permutations.push_back(p);
        
        for(int i=0;i<size(nums);i++)
        {
            if(i>0&&nums[i]==nums[i-1])continue;
           vector<int>temp;
            for(int j=0;j<size(nums);j++)
            {
                if(j!=i)
                    temp.push_back(nums[j]);
            }
            p.push_back(nums[i]);
            backtrack(temp,p);
            p.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
    sort(begin(nums),end(nums));
    backtrack(nums,{});
    return permutations;
    }
};