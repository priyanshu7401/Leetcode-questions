class Solution {
public:
    int longestValidParentheses(string s) 
    {
        stack<int>st;
        int ans=0;
        st.push(-1);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else
            {
                if(st.top()!=-1&&s[st.top()]=='(')
                {
                    
                    st.pop();
                }    
                else
                {
                    st.push(i);
                }
            }
            ans=max(ans,i-st.top());
                
        }
        return ans;
    }
};