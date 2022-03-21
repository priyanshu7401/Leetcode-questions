class Solution {
public:
    string reorganizeString(string s) 
    {
        unordered_map<char,int>map;
        for(int i=0;i<size(s);i++)map[s[i]]++;
        vector<pair<char,int>>vec;
        for(auto [i,j]:map)
        {
            vec.push_back({i,j});
        }
        auto cmp=[&](pair<char,int>a,pair<char,int>b){
            return a.second>b.second;
        };
        sort(begin(vec),end(vec),cmp);
        int i=0,j=0;
        for(;i<size(vec)&&j<s.size();)
        {
            s[j]=vec[i].first;
            vec[i].second--;
            j+=2;
            if(vec[i].second==0)
                i++;
        }
        j=1;
        for(;i<size(vec)&&j<s.size();)
        {
            s[j]=vec[i].first;
            if(s[j-1]==s[j])
                return "";
            vec[i].second--;
            j+=2;
            if(vec[i].second==0)
                i++;
        }        
        return s;
    }
};