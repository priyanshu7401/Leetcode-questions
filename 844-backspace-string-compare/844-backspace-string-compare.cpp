class Solution {
public:
    string process(string s)
    {
        string s1(s.size(),'a');
        int j=0;
        for(int i=0;i<size(s);i++)
        {
            if(s[i]!='#')
            {
                s1[j++]=s[i];
            }
            else j=max(j-1,0);
        }
        return s1.substr(0,j);
    }
    bool backspaceCompare(string s, string t) 
    {
        return process(s)==process(t);
    }
};