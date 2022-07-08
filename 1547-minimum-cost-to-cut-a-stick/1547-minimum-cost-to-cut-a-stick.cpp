class Solution {
public:
    int memo[103][103]={};
    int dp(vector<int>&cuts,int first,int last)
    {
        if(last<=first+1)
            return 0;
        // cout<<first<<" "<<last<<endl;
        if(memo[first][last]!=0)
            return memo[first][last];
        int ans=INT_MAX;
        for(int i=first+1;i<last;i++)
        {
        
            ans=min(ans,cuts[last]-cuts[first]+dp(cuts,first,i)+dp(cuts,i,last));
        }
        return memo[first][last]=ans;
    }
    int minCost(int n, vector<int>& cuts) 
    {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(begin(cuts),end(cuts));
        return dp(cuts,0,cuts.size()-1);    
    }
};