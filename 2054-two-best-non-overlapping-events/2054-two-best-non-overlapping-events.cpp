
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) 
    {
    sort(begin(events),end(events));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int last=0,ans=0;
    for(int i=0;i<size(events);i++)
    {
        while(!pq.empty()&&pq.top().first<events[i][0])
        {
            auto job=pq.top();
            pq.pop();
            last=max(last,job.second);
        }
        ans=max(ans,last+events[i][2]);
        pq.push({events[i][1],events[i][2]});
    }
        return ans;
    }
};