class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words)
    {
    vector<vector<pair<string,int>>>vec(128);
    for(int i=0;i<words.size();i++)
    {
        vec[words[i][0]].push_back({words[i],0});
    }
    int count=0;
    int sz=words.size();
    int i=0;
    while(sz&&i!=s.length())
    {
        vector<pair<string,int>>tempo;
        for(int j=vec[s[i]].size()-1;j>=0;j--)
        {
            pair<string,int>temp=vec[s[i]][j];
            temp.second++;
            // cout<<temp.first<<" "<<temp.second<<endl;
            vec[s[i]].pop_back();
            if(temp.second==temp.first.size())
            {
                sz--;
                count++;
                continue;
            }
            if(temp.first[temp.second]!=s[i])
                vec[temp.first[temp.second]].push_back(temp);
            else
                tempo.push_back(temp);
        }
        for(int k=0;k<tempo.size();k++)
            vec[s[i]].push_back(tempo[k]);
        i++;
    }
    return count;
    }
};