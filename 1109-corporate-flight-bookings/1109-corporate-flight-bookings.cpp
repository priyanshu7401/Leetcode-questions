class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) 
    {
    vector<int>prefix(n,0);
    for(int i=0;i<size(bookings);i++)
    {
        prefix[bookings[i][0]-1]+=bookings[i][2];//if(starting add it into the path rememebr (prefix is zero index and given data is 1 indexed))
        if(bookings[i][1]<n)
            prefix[bookings[i][1]]+=-1*bookings[i][2];//if that booking ends simply do -of that value so that it is removed from the current totally booked values.
    }
    int sum=0;
    for(int i=1;i<n;i++)
    {
        prefix[i]+=prefix[i-1];
    }
        return prefix;
    }
};