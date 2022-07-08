class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) 
    {
        map<int,vector<int>>mp;
        for(int i=0;i<size(reservedSeats);i++)
        {
            mp[reservedSeats[i][0]].push_back(reservedSeats[i][1]);
        }
        int prev_row=0,ans=0;
        for(auto [i,seats]:mp)
        {
            ans+=(i-prev_row-1)*2;
            prev_row=i;
            vector<int>vec(11,0);
            for(int j=0;j<seats.size();j++)
            {
                vec[seats[j]]=1;
            }
            int temp=0;
            temp+=((vec[2]+vec[3]+vec[4]+vec[5])==0);
            temp+=((vec[4]+vec[5]+vec[6]+vec[7])==0);
            temp+=((vec[6]+vec[7]+vec[8]+vec[9])==0);
            // cout<<temp<<" "<<endl;
            ans+=(temp/2)+(temp==1||temp==3);
        }
        ans+=(n-prev_row)*2;
        return ans;
    }
};