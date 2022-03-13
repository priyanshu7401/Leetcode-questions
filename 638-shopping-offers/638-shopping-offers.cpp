#define all(a) (a).begin(), (a).end()
class Solution {
public:
    int n;
    int dp(vector<vector<int>>&special,vector<int>&needs,int i)
    {
       int ans=1e5,flag=0;
       if(accumulate(all(needs),0)==0)
            return 0;
       if(i==size(special))return 1e5;
       for(int j=0;;j++)
       {
           vector<int>temp=needs;
           int k=0;
           for(;k<n;k++)
           {       
               temp[k]-=j*special[i][k];
               if(temp[k]<0)break;
           }
           if(k!=n)
               return ans;
           ans=min(ans,j*special[i][n]+dp(special,temp,i+1));
       }
        return 0;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) 
    {
        n=size(price);
        for(int i=0;i<size(price);i++)
        {
            vector<int>temp(n+1,0);
            temp[i]=1;
            temp[n]=price[i];
            special.push_back(temp);
        }
        int ans=dp(special,needs,0);
        return ans;
    }
};