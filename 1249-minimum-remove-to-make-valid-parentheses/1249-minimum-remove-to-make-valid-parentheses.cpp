class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        stack<int>st;
        set<int>set;
        int n=size(s);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
                set.insert(i);
            }
                
            if(s[i]==')')
            {
                if(!st.empty()&&s[st.top()]=='(')
                {
                    set.erase(st.top());
                    st.pop();
                }
                else
                { 
                    st.push(i);
                    set.insert(i);
                }
            }   
        }
    string ans="";
    for(int i=0;i<n;i++)
    {
        if(set.find(i)==set.end())
            ans+=s[i];
    }
        return ans;
    }
};