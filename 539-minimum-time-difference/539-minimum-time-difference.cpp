class Solution {
public:
    int findMinDifference(vector<string>& timePoints) 
    {
    int n=size(timePoints);
    auto mycmp=[&](string a,string b)
    {
        return a<b;
    };
    sort(begin(timePoints),end(timePoints),mycmp);
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int temp1=((timePoints[(i-1+n)%n][0]-'0')*10+(timePoints[(i-1+n)%n][1]-'0'))*60+(timePoints[(i-1+n)%n][3]-'0')*10+(timePoints[(i-1+n)%n][4]-'0');
        int temp2=((timePoints[i][0]-'0')*10+(timePoints[i][1]-'0'))*60+(timePoints[i][3]-'0')*10+(timePoints[i][4]-'0');
        ans=min(ans,min(abs(temp2-temp1),1440-abs(temp2-temp1)));
    }
        return ans;
    }
};