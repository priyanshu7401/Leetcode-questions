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
           if(num%2==0&&map.count(num/2)&&(ones-num)==num/2)
               count=1LL*(count+map[num/2])%mod;
           map[num]++;
     }
        return count;
    }
};