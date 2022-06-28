class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
    map<int,int>map;
    for(int i=0;i<size(hand);i++)
    {
        map[hand[i]]++;
    }
    for(auto [card,count]:map)
    {
        if(count==0)
            continue;
        int i =card;
        while(i<card+groupSize)
        {
            // cout<<i<<" "<<endl;
            if(map[i]>=count)
                map[i]-=count;
            else
                return false;
            i++;
        }
    }
        return true;
    }
};