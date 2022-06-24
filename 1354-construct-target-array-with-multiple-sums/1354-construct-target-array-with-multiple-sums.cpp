class Solution {
public:
    bool isPossible(vector<int>& target) 
    {
        long long sum=accumulate(begin(target),end(target),1LL*0);
        priority_queue<int>pq(begin(target),end(target));
        while(pq.top()>1)
        {
            int num=pq.top();
            pq.pop();
            sum-=num;
            if (sum == 1)
                return true;
            if(sum>=num||sum==0||num%sum==0)
                return false;
            pq.push(num%sum);
            sum+=num%sum;
        }
        return true;
    }
};