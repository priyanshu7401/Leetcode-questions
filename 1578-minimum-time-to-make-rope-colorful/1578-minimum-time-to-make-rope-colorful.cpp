class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) 
    {
    int ans=0,n=size(colors);
    for(int i=0;i<n;)
    {
     int maxi=neededTime[i],j=i+1,sum=neededTime[i];
     while(j<n&&colors[i]==colors[j])
     {
         sum+=neededTime[j];
         maxi=max(neededTime[j],maxi);
         j++;
     }
     if(i+1!=j)
     {
      ans+=sum-maxi;   
     }
        i=j;
    }
        return ans;
    }
};