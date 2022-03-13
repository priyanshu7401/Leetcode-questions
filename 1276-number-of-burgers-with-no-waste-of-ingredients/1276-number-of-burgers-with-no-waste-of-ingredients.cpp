class Solution {
public:
    vector<int> numOfBurgers(int a, int b) 
    {
      vector<int> ans={(a-2*b)/2,(4*b-a)/2};
     if(ans[0]+ans[1]==b&&ans[0]>=0&&ans[1]>=0&&4*ans[0]+2*ans[1]==a)
         return ans;
        return {};
    }
};