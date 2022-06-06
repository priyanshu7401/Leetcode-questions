class Solution {
public:
    int mod=1e9+7;
    int numWays(string s) 
    {
     unordered_map<int,int>map;
     int num=0,count=0;
     for(int i=0;i<size(s);i++)
     {
           num+=(s[i]=='1');
           map[num]++;
     }
     if(num%3)
         return 0;
     if(num==0)
     {
         return (1LL*(map[0]-1)*(map[0]-2)/2)%mod;
     }
        return (1LL*map[num/3]*map[(2*num)/3])%mod;
    }
};