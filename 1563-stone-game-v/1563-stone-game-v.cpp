class Solution {
public:
    int memo[501][501];
    int dp(vector<int>& s,int i,int j)
    {
        if(i>=j)
            return 0;
        if(memo[i][j]!=0)
            return memo[i][j];
        int ans=0,lastsum=i>0?s[i-1]:0;
        for(int k=i;k<=j;k++)
        {
            if(s[k]-lastsum<=s[j]-s[k])
                ans=max(ans,s[k]-lastsum+dp(s,i,k));
            if(s[j]-s[k]<=s[k]-lastsum)
                ans=max(ans,s[j]-s[k]+dp(s,k+1,j));
        }
        return memo[i][j]=ans;
    }
    int stoneGameV(vector<int>& stoneValue) 
    {
     int n=size(stoneValue);
     for(int i=1;i<n;i++)   
        stoneValue[i]+=stoneValue[i-1];
    // for(int i=0;i<n;i++)
    //     cout<<stoneValue[i]<<" ";
    return dp(stoneValue,0,n-1);   
    }
};