class Solution {
public:
    double average(vector<int>& salary) 
    {
     sort(begin(salary),end(salary));
     double sum=accumulate(begin(salary)+1,end(salary)-1,1LL*0);
     return sum/(size(salary)-2);
    }
};