class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) 
    {
    sort(begin(s1),end(s1));
    sort(begin(s2),end(s2));
    int count1=0,count2=0,n=size(s1);
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]<=s2[i])
            count1++;
        if(s1[i]>=s2[i])
            count2++;
    }
        return count1==n||count2==n;
    }
};