class Solution {
public:
    vector<vector<int>>memo;
    int dp(vector<vector<int>>&team,int i,int prev)
    {
        if(i==size(team))
            return 0;
        if(prev>=0&&memo[i][prev]!=-1)
            return memo[i][prev];
        int ans=dp(team,i+1,prev);
        if(team[prev][1]<=team[i][1])
        {
            ans=max(ans,team[i][1]+dp(team,i+1,i));
        }
        return memo[i][prev]=ans;
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) 
    {
    int n=size(scores);
    vector<vector<int>>team={{0,0}};
    memo.resize(n+1,vector<int>(n+1,-1));
    for(int i=0;i<n;i++)
    {
        team.push_back({ages[i],scores[i]});
    }
    sort(begin(team),end(team),[&](vector<int>&a,vector<int>&b)
     {
         if(a[0]!=b[0])
                return a[0]<b[0];
         else
                return a[1]<b[1];
     });
    
        return dp(team,1,0);
    }
};