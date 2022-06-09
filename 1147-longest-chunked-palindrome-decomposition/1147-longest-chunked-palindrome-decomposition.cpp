class Solution {
public:
    int longestDecomposition(string text) 
    {
    int n=text.size(),ans=0,i=0,j=n-1;
    string start="";
    string end="";
    while(i<j)
    {
        start+=text[i++];
        end=text[j--]+end;
        if(start==end)
        {
            ans+=2;
            start="";
            end="";
        }
    }
        return ans+(start+end!=""||i==j);
    }
};