class Solution {
public:
    vector<int>memo;
    unordered_set<string>st;
    bool dp(string s,unordered_set<string>&set,int i=0)
    {
        if(i==s.size())
            return true;
        string temp="";
        if(memo[i]!=-1)
            return memo[i];
        for(int j=i;j<size(s);j++)
        {
            temp+=s[j];
            if(set.find(temp)!=set.end()&&(dp(s,set,j+1)))
            {
        
                return memo[i]=true;
            }
        }
        return memo[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) 
    {
    memo.resize(size(s),-1);
    unordered_set<string>set(begin(wordDict),end(wordDict));
    return dp(s,set,0);
    }
};




