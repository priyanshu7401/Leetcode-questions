class Solution {
public:
    vector<int>dp;
    int memo(vector<int>&arr,int i,int d)
    {
        if(dp[i]!=0)
            return dp[i];
        
        int ans=0,j=i+1,n=size(arr);
        
        while(j<min(i+d+1,n)&&arr[i]>arr[j])
            ans=max(ans,memo(arr,j,d)),j++;
        
        j=i-1;
        while(j>=max(i-d,0)&&arr[i]>arr[j])
            ans=max(ans,memo(arr,j,d)),j--;
        
        return dp[i]=ans+1;
        
    }
    int maxJumps(vector<int>& arr, int d) 
    {
        int ans=0,n=size(arr);        
        dp.resize(n,0);
 
        for(int i=0;i<n;i++)
        {
            ans=max(ans,memo(arr,i,d));
        }
        return ans;
    }
};