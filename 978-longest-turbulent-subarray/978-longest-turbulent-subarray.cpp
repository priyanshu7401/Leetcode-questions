class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) 
    {
    int n=size(arr),ans=min(1,n),turb=1;
    for(int i=1;i<n;i++)
    {
        if(i>=2&&arr[i]>arr[i-1]&&arr[i-1]<arr[i-2])
            turb++;
        else if(i>=2&&arr[i]<arr[i-1]&&arr[i-1]>arr[i-2])
            turb++;
        else
            turb=1+(arr[i]!=arr[i-1]);
        ans=max(ans,turb);
    }
        return ans;
    }
};