class Solution {
public:
    string longestPalindrome(string s)
    {
    if(s.length()<=1)
        return s;
    int len=s.length();
    bool dp[len][len];
    int maxlen=0;
    int start=0;    
    for(int i=len-1;i>=0;i--)
    {
        for(int j=i;j<len;j++)
        {
            if(i==j)
            dp[i][j]=true;
            else
                dp[i][j]=(i==j-1)?s[i]==s[j]:(s[i]==s[j])&&(dp[i+1][j-1]);  
            if(dp[i][j]&&j-i+1>=maxlen)
            {
                maxlen=j-i+1;
                start=i;
            }
        }
    }
       return s.substr(start,maxlen); 
    }
    
};