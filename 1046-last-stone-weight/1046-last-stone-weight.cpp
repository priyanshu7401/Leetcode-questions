class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
    priority_queue<int>pq;
    for(int i=0;i<size(stones);i++)
        pq.push(stones[i]);
    while(pq.size()>1)
    {
        int s1=pq.top();
        pq.pop();
        int s2=pq.top();
        pq.pop();
        if(s1!=s2)
        {
            pq.push(abs(s1-s2));
        }
    }
        return pq.size()?pq.top():0;
    }
};