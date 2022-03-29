class Solution {
public:
    vector<vector<int>>memo;
    unordered_set<string>st;
    bool dp(string s,int i=0,int j=0,string temp="")
    {
        if(i==s.size())
        {
            if(j==s.size())
                return true;
            return false;
        }
        if(memo[i][j]!=-1)
            return memo[i][j];
        bool ans1=false,ans2=false;
        temp+=s[i];
        ans1=dp(s,i+1,j,temp);
        
        if(st.find(temp)!=st.end())
        {   
            ans2=dp(s,i+1,i+1,"");
        }
        return memo[i][j]=ans1|ans2;
    }
    bool wordBreak(string s, vector<string>& wordDict) 
    {
    memo.resize(size(s),vector<int>(size(s),-1));
    unordered_set<string>set(begin(wordDict),end(wordDict));
    st=set;
    return dp(s,0,0);
    }
};




