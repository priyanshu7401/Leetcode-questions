class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) 
    {
    int mini=INT_MAX;
    for(int i=1;i<=9999;i++)
    {
        int seconds=((i/100)*60)+(i%100);
    
        if(seconds!=targetSeconds)
            continue;
        
        int start=startAt,count=0,j=0;
        string s=to_string(i);
        while(j<s.size())
        {
            if(s[j]!=start+'0')
                count+=moveCost+pushCost;
            else
                count+=pushCost;  
            start=s[j++]-'0';
        }
        mini=min(mini,count);   
    }
        // cout<<endl;
        return mini;
    }
};