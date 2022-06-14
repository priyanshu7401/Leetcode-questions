class Solution {
public:
    int minDistance(string a, string b) 
    {
        int m=a.size(),n=b.size();
        vector<int>dp1(n+1,0),dp2(n+1,0);
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0||j==0)
                {
                    dp1[j]=i+j;
                    continue;
                }
                if(a[i-1]==b[j-1])
                {
                    dp1[j]=(dp2[j-1]);
                    continue;
                }
                dp1[j]=1+min(dp2[j],dp1[j-1]);
            }
            dp2=dp1;
        }
        return dp2[n];
    }
};