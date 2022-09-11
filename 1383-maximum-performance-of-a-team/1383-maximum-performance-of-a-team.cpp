class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k)
    {
    vector<pair<int,int>>collections(n);
    for(int i=0;i<n;i++)
    {
        collections[i]={efficiency[i],speed[i]};
    }
    sort(collections.begin(),collections.end(),[](const auto&a,const auto&b)->bool{return  a.first>b.first;});
    long long speedsum=0;
    long long ans=0;
    int mod=1e9+7;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(auto & c:collections)
    {
        if(pq.size()>k-1)                    
        {
            speedsum-=pq.top();
            pq.pop();
        }
        speedsum+=c.second;
        pq.push(c.second);
        ans=max(ans,c.first*speedsum);
    }
    return ans%(mod);
    }
};