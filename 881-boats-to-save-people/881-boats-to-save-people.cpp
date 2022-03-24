class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
    sort(begin(people),end(people));
    int i=0,j=size(people)-1,count=0;
        
    while(i<=j)
    {
        if(people[i]+people[j]<=limit)
            i++,j--;
        else
            j--;
        count++;
    }
        return count;
    }
};