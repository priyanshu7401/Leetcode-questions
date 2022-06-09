class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int th) 
    {
    int sum=0,ans=0,j=0,n=size(arr);
    for(int i=0;i<size(arr);i++)
    {
        sum+=arr[i];
        if(i>=k-1)
        {
         if(k*th<=sum)
             ans++;
         sum-=arr[i-k+1];
        }
    }
        return ans;
    }
};