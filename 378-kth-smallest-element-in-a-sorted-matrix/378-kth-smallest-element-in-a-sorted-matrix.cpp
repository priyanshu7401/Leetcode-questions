struct mycomp
{
    bool operator()(const vector<int>& x, const vector<int>& y)
    {
        return  x[0]>y[0];
    }
};

class Solution {
public:
    struct numCompare {
    bool operator()(const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y) {
      return x.first > y.first;
    }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
    int m=matrix.size();
    int n=matrix[0].size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, numCompare>  pq;
    for(int i=0;i<m;i++)
    {
        pq.push({matrix[i][0],{i,0}});
    }
    while(k!=1)
    {
        auto x=pq.top();
        pq.pop();
        k--;
        if(x.second.second+1<n)
        {
            pq.push({matrix[x.second.first][x.second.second+1],{x.second.first,x.second.second+1}});
        }
        
    }
        return pq.top().first;
    }
};