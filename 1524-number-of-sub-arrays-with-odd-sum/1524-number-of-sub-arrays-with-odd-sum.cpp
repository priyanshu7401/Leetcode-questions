class Solution {
public:
    int numOfSubarrays(vector<int>& arr) 
    {
    int odd=0,even=0;
    long long ans=0;
    int mod=1e9+7;
    for(auto num:arr)
    {
        if(num%2)
        {
            swap(even,odd);
            odd+=1;
        }
        else
        {
            even+=1;
        }
        ans=(ans+odd)%mod;
    }
        return ans;
    }
};