class Solution {
    vector<int>dp;
public:
    Solution() : dp(101,-1){}
    int numDecodings(string s)
    {

    if(s.length()==0)
    {
        return 1;
    }
    if(dp[s.length()]!=-1)
        return dp[s.length()];
    if(s[0]=='0')
        return 0;
    int ans=0,ans1=0;
    ans=numDecodings(s.substr(1));
    if(s.length()>=2)
    {
        int num=(s[0]-48)*10+(s[1]-48);
    if(num<=26)
        ans1=numDecodings(s.substr(2));
    }
    return dp[s.length()]=ans+ans1;
    }
};