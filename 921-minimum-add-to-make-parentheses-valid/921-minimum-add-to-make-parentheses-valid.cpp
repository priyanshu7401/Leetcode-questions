class Solution {
public:
    int minAddToMakeValid(string num) 
    {
    stack<char>st;
    for(int i=0;i<size(num);i++)
    {
        if(!st.empty()&&st.top()=='('&&num[i]==')')
            st.pop();
        else
            st.push(num[i]);       
    }
        return st.size();
    }
};