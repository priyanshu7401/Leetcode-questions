// bool dp(string s,unordered_set<string>&set,int i,vector<int>&memo)
// {
//     if(i==s.size())
//         return true;
//     string temp="";
//     if(memo[i]!=-1)
//         return memo[i];
//     for(int j=i;j<size(s);j++)
//     {
//         temp+=s[j];
//         if(set.find(temp)!=set.end()&&(dp(s,set,j+1,memo)))
//         {
//             return memo[i]=true;
//         }
//     }
//     return memo[i]=false;
// }

class Solution {
public:
    
    bool dp(string& s,unordered_set<string>&set)
    {
        int n=size(s);
        vector<int>memo(n+1,0);
        memo[n]=true;
        for(int i=n-1;i>=0;i--)
        {
            string temp="";
            for(int j=i;j<n;j++)
            {
                temp+=s[j];
                if(set.find(temp)!=set.end()&&memo[j+1])
                {
                    memo[i]=true;
                    break;
                }
            }
        }
        return memo[0];
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words)
    {
    unordered_set<string>set(begin(words),end(words));
    vector<string>ans;
    for(int i=0;i<size(words);i++)
    {
        if(!words[i].size())
            continue;
        set.erase(words[i]);
        if(dp(words[i],set))
            ans.push_back(words[i]);
        set.insert(words[i]);
    }
        return ans;
    }
};