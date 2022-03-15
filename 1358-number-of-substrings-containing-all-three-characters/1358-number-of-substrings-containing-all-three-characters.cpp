class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        vector<int>vec(3,-1);
        int n=size(s),ans=0;
        int j=0;
        for(int i=0;i<n;i++)
        {
            vec[s[i]-'a']=i;
            ans+=1+min(vec[0],min(vec[1],vec[2])); 
        }
        return ans;
    }
};