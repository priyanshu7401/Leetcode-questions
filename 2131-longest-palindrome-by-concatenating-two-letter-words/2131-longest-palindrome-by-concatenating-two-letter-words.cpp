class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
    int ans=0;
    unordered_map<string,int>map;
    for(string i:words)
    {   
        map[i]++;
           
    }
    int flag=1;
    for(auto [i,j]:map)
    {

        string x="";
        x+=i[1];
        x+=i[0];
        if(map.count(x))
        {
            if(x!=i)
                ans+=2*min(j,map[x]);
            else
            { 
                ans+=4*(j/2);
                if(flag==1&&j%2)
                    ans+=2,flag=0;
            }
        }
        
    }
        return ans;
    }
};