class Solution {
public:
    int mod=1e9+7;
    int numWays(string s) 
    {
     unordered_map<int,int>map;
     int ones=count(s.begin(), s.end(), '1');
     int num=0,count=0;
     for(int i=0;i<size(s)-1;i++)
     {
           num+=(s[i]=='1');
           // if(num%2==0&&map.count(num/2)&&(ones-num)==num/2)
           //     count=1LL*(count+map[num/2])%mod;
           map[num]++;
     }
     if(ones%3)
         return 0;
     if(ones==0)
     {
         return (1LL*map[0]*(map[0]-1)/2)%mod;
     }
        return (1LL*map[ones/3]*map[(2*ones)/3])%mod;
    }
};