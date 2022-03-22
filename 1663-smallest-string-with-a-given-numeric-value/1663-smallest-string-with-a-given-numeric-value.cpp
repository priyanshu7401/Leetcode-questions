class Solution {
public:
    string getSmallestString(int n, int k) 
    {
        string ans(n,'a');
        k=k-n;
        int i=n-1;
        while(k)
        {
            int mini=min(k,25);
            ans[i--]='a'+mini;
            k-=mini;
        }
        return ans;
    }
};
    