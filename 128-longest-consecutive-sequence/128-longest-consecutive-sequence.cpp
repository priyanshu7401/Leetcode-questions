
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
    int n=nums.size();
    unordered_map<int,bool>mp;
    for(int i=0;i<n;i++)
    {
        mp[nums[i]]=false;
    }
    int longest=0;
    for(int i=0;i<n;i++)
    {
        if(mp[nums[i]]==true||mp.find(nums[i]-1)!=mp.end())
            continue;
        else
        {
            int count=1;
            int x=nums[i]+1;
            while(mp.find(x)!=mp.end())
            {
                count++;
                mp[x++]=true;
            }
            longest=max(longest,count);
        }
    }
        return longest;
    }
};
