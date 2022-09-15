class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) 
    {
    map<int,int>map;
    int n=nums.size();
    for(int i=0;i<size(nums);i++)
    {
        map[nums[i]]+=1;
    }
    vector<int>ans;
    for(auto[i,j]:map)
    {
        while(map.count(2*i)&&map[i]>0&&map[2*i]>0)
        {
            if(i!=0)
            {
            ans.push_back(i);
            map[i]--;
            map[2*i]--;
            }
            else if(map[2*i]%2==0)
            {
                ans.push_back(i);
                map[i]-=2;
            }
            else 
                return {};
        }
    }
        if(2*ans.size()==n)return ans;
        return {};
    }
};
    // for(int i=0;i<n;i++)
    // {
    //     if(map[nums[i]]<=0)continue;
    //     if(map.count(2*nums[i])&&map[2*nums[i]]>0)
    //     {   
    //         if(nums[i]!=0)
    //         {   
    //         ans.push_back(nums[i]);
    //         map[2*nums[i]]--;
    //         }
    //         else
    //         {
    //             if(map[nums[i]]>1
    //         }
    //     }
    // }