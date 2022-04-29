class Solution {
public:
    int maxVowels(string s, int k) 
    {
    set<char>set({'a','e','i','o','u'});  
    int ans=0,count=0;
    for(int i=0;i<size(s);i++)
    {
        if(i-k>=0)
            count-=(set.find(s[i-k])!=set.end());
        count+=(set.find(s[i])!=set.end());
        ans=max(ans,count);
    }
        return ans;
    }
};