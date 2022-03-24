class Solution {
public:
    vector<string>ans;
    void backtrack(string s,int i)
    {
        if(s.size()==i)
        {
            ans.push_back(s);
            return;
        }
        backtrack(s,i+1);
        if(s[i]>='A'&&s[i]<='Z')
        {
            s[i]=s[i]+32;
            backtrack(s,i+1);
        }
        else if(s[i]>='a'&&s[i]<='z')
        {
            s[i]=s[i]-32;
            backtrack(s,i+1);
        }
        return;
    }
    vector<string> letterCasePermutation(string s) 
    {
        backtrack(s,0);
        return ans;
    }
};