class Solution {
public:
    int thirdMax(vector<int>& nums) 
    {
    set<int,greater<int>>s(begin(nums),end(nums));
    int count=0;
    for(auto i : s)
    {
        count++;
        if(count==3)
            return i;
    }
        return *s.begin();
    }
};