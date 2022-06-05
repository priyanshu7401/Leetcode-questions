class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) 
    {
        vector<int>ans;
       for(int i=0;i<matrix.size();i++)
       {
           int mini=min_element(begin(matrix[i]),end(matrix[i]))-begin(matrix[i]);
           int maxi=0;
           for(int j=0;j<size(matrix);j++)
           {
               maxi=max(maxi,matrix[j][mini]);
           }
           if(maxi==matrix[i][mini])
               ans.push_back(maxi);
       }
        return ans;
    }
};