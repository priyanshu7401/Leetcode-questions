class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
    sort(begin(people),end(people),[](vector<int>&a,vector<int>&b){return a[1]<b[1];}); 
    for(int i=1;i<size(people);i++)
    {
        int k=people[i][1];
        int j=0;
        for(;j<i&&k>=0;j++)
        {
            if(people[j][0]>=people[i][0])k--;
            if(k<0)break;
        }
        for(int k=i;k>j;k--)swap(people[k],people[k-1]);
    }
    return people;
    }
};