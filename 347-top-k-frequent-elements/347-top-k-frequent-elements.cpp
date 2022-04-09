class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
    unordered_map<int,int>map;
    for(int i=0;i<size(nums);i++)
    {
        map[nums[i]]++;
    }
    vector<vector<int>>temp(1e5+1);
    vector<int>ans;
    for(auto [i,j]:map)
    {
        temp[j].push_back(i);
    }
    for(int i=1e5;i>=0;i--)
    {
        for(int j=0;j<size(temp[i]);j++)
        {
            ans.push_back(temp[i][j]);
            k--;
            if(k==0)
                return ans;            
        }

   }
        return ans;
    }
};