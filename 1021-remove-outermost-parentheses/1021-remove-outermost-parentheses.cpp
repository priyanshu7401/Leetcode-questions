class Solution {
public:
    string removeOuterParentheses(string s) 
    {
    stack<char>st;
    string temp="";
    string ans="";
    for(int i=0;i<size(s);i++)
    {
        if(s[i]=='(')
        {
            temp+=s[i];
            st.push('(');
        }
        if(s[i]==')')
        {
            st.pop();
            temp+=s[i];
        }
        if(st.empty())
        {
          ans+=temp.substr(1,size(temp)-2);
          temp="";  
        }
        
    }
        return ans;
    }
};