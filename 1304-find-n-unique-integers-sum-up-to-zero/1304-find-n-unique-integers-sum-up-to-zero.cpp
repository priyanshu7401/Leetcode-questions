class Solution {
public:
    vector<int> sumZero(int n) 
    {
    vector<int>ans(n,0);
    long long sum=0;
    for(int i=0;i<n-1;i++)
    {
        ans[i]=i+1;
        sum+=i+1;
    }
        ans[n-1]=-1*sum;
        return ans;
    }
};