class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& a) {
        auto comp = [](const vector<int>& a, const vector<int>& b)
        {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        };
        sort(a.begin(), a.end(), comp);
        int ans = 0, maxSecond = INT_MIN, n = a.size();
        for(int i = n - 1; i >= 0; i--)
        {
            if(a[i][1] < maxSecond)
            {
                ans++;
            }
            maxSecond = max(maxSecond, a[i][1]);
        }
        return ans;
    }
};


        // while(!pq.empty())
        // {
        //     cout<<pq.top()[0]<<" "<<pq.top()[1]<<endl;
        //     auto temp=pq.top();
        //     if(temp[0]<a[i][0]&&temp[1]<a[i][1])pq.pop();
        //     else break;
        // }
        // pq.push(a[i]);
        // i++;