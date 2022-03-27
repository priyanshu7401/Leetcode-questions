class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
   
    vector<pair<int,int>>soldiers;
    for(int i=0;i<mat.size();i++)
    {
        int lo=0,hi=size(mat[i]);
        while(lo<hi)
        {
            int mid=(lo+hi)/2;
            if(mat[i][mid])
                lo=mid+1;
            else
                hi=mid;
        }
        soldiers.push_back({i,lo});
    }
    auto mycmp=[&](pair<int,int>a,pair<int,int>b)
    {
        if(a.second-b.second)
            return a.second<b.second;
        return a.first<b.first;
    };
    sort(begin(soldiers),end(soldiers),mycmp);
    vector<int>ans;
    int n=size(soldiers);
    for(int i=0;i<min(n,k);i++)
    {
        ans.push_back(soldiers[i].first);
    }
        return ans;
    }
};