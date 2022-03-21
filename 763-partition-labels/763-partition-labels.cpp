class Solution {
public:
    vector<int> partitionLabels(string s)
    {
    vector<int>ans;
    unordered_map<char,int>map;
    for(int i=0;i<s.size();i++)
    {
        map[s[i]]=i;
    }
    int last=0;
    int start=-1; 
    for(int i=0;i<s.size();i++)
    {
        last=max(last,map[s[i]]);
        if(i==last)
        {
            ans.push_back(last-start);
            start=last;
        }
    }
    return ans;
    }
};