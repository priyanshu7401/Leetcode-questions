class Solution {
public:
    string smallestSubsequence(string s) 
    {
        vector<int>index(26,0),visited(26,0);
        stack<char>st;
        for(int i=0;i<size(s);i++)//store the last index
            index[s[i]-'a']=i;
        
        for(int i=0;i<size(s);i++)
        {
            if(visited[s[i]-'a'])
                continue;
            while(!st.empty()&&s[i]<st.top()&&index[st.top()-'a']>i)
            {
                visited[st.top()-'a']=0;
                st.pop();
            }
            st.push(s[i]);
            visited[s[i]-'a']=1;
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};