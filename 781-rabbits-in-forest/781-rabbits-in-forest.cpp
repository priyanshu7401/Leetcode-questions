class Solution {
public:
    int numRabbits(vector<int>& answers) 
    {
        unordered_map<int,int>map;
        int ans=0;
        for(int i=0;i<size(answers);i++)
        {
            map[answers[i]+1]++;
        }
        for(auto [num,count]:map)
        {
            ans+=num*ceil(count*1.0/num);
        }
        return ans;
    }
};