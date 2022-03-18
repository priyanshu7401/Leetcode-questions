class Solution {
public:
    int minAddToMakeValid(string num) 
    {
    int ans=0,bal=0;
    for(int i=0;i<size(num);i++)
    {
        if(num[i]=='(')
            bal++;
        if(num[i]==')')
            bal--;
        if(bal==-1)
        {
            ans++;
            bal=0;
        }
    }
        return ans+bal;
    }
};