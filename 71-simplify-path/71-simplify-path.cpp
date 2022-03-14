class Solution {
public:
    string simplifyPath(string s) 
    {
    int n=size(s);
    string res="";
    stack<string>st;
    for(int i=0;i<n;i++)
    {
        string temp="";
        while(i<n&&s[i]!='/')
        {
            temp+=s[i++];
        }
        if(temp==""||temp==".")
            continue;
        if(temp=="..")
        {
            if(!st.empty())
                st.pop();
        }
        else
        {
            st.push(temp);
        }
    }
    vector<string>ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<size(ans);i++)
    {
        res+='/'+ans[i];
    }
    return res.size()!=0?res:"/";
    }
};