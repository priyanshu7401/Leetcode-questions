class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern)
    {
        vector<string>ans;
        int n=size(words);
        for(int i=0;i<n;i++)
        {
            vector<char>s1(26,0),s2(26,0);
            int j=0;
            for(;j<words[i].size();j++)
            {
                if((s1[words[i][j]-'a']!=0&&s1[words[i][j]-'a']!=pattern[j])||(s2[pattern[j]-'a']!=0&&s2[pattern[j]-'a']!=words[i][j]))
                    break;
                s1[words[i][j]-'a']=pattern[j];
                s2[pattern[j]-'a']=words[i][j];
            }
            if(j==words[i].size())
            {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};