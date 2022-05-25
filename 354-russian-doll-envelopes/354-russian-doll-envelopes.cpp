class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        int n=size(envelopes),len=0;
         auto mycmp=[&](vector<int>&a,vector<int>&b)
         {
             if(a[0]!=b[0])
                return a[0]<b[0];
             return a[1]>b[1];
         };
        sort(begin(envelopes),end(envelopes),mycmp);
        vector<int>LIS(n);
        for(int i=0;i<n;i++)
        {
            int index=lower_bound(begin(LIS),begin(LIS)+len,envelopes[i][1])-begin(LIS);
            LIS[index]=envelopes[i][1];
            if(index==len)len++;
        }
        return len;
    }
};