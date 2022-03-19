class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        string ans="";
        stack<char>stack;
        vector<int>vis(26,0);
        vector<int>res(26,0);
        
        for(auto ch:s)res[ch-'a']++;
        
        for(int i=0;i<size(s);i++)
        {
            res[s[i]-'a']--;
            
            if(vis[s[i]-'a'])
                continue;
            
            while(!stack.empty()&&s[i]<stack.top()&&res[stack.top()-'a']!=0)
            {
                vis[stack.top()-'a']=0;
                stack.pop();
            }
            stack.push(s[i]);
            vis[s[i]-'a']++;
        }
        while(!stack.empty())
        {
            ans+=(stack.top());
            stack.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }

};

