class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        int bal=0,last=0;
        string ans="";
        for(int i=0;i<size(s);i++)
        {
            if(s[i]=='(')
                bal++;
            else
                bal--;
            if(bal==0)
            {
                ans+=s.substr(last+1,i-last-1);
                last=i+1;
            }
        }
        return ans;
    }
};