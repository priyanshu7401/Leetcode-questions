class Solution {
public:
    int memo[601][101][101];
    int dp(vector<string>& strs,int i,int m,int n)
    {
        if(m<0||n<0)return INT_MIN;
        if(i==size(strs))
            return 0;
        if(memo[i][m][n]!=-1)return memo[i][m][n];
        int zeros=0;
        int ones=0;
        for(int j=0;j<strs[i].size();j++)
        {
            zeros+=(strs[i][j]=='0');
            ones+=(strs[i][j]=='1');
        }
        return memo[i][m][n]=max(1+dp(strs,i+1,m-zeros,n-ones),dp(strs,i+1,m,n));
    }
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
    for(int i=0;i<=600;i++)
        for(int j=0;j<=100;j++)
            for(int k=0;k<=100;k++)
                memo[i][j][k]=-1;
        
    for(int i=n-1;i>=0;i--)
    {
        
    }
    
    return dp(strs,0,m,n);    
    }
};

//states
//(how many ones,how many ones left)
//now i can decide whehter i select a string or not