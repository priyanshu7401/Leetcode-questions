class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
    stack<vector<long long>>s;
    long long ans=0;
    s.push({-1,0});
    long long mod=1e9+7;
    for(int i=0;i<size(arr);i++)
    {
        while(s.top()[0]!=-1&&arr[s.top()[0]]>=arr[i])
            s.pop();
        
        vector<long long>temp={i,(arr[i]*(i-s.top()[0])+s.top()[1])%mod};
        ans=(ans+temp[1])%mod;
        s.push(temp);
    }
        return ans;
    }
};