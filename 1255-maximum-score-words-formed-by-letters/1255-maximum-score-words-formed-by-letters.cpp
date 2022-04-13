class Solution {
public:
    unordered_map<int,int>map;
    int dp(vector<string>&words,int i,vector<int>&scores)
    {
        if(size(words)==i)
            return 0;
        int ans=dp(words,i+1,scores),sum=0,j=0;
        for(j=0;j<size(words[i]);j++)
        {
            if(map[words[i][j]]>0)
                map[words[i][j]]--;
            else 
            {
                break;
            }
            sum+=scores[words[i][j]-'a'];
        }
        if(j==size(words[i]))
            ans=max(ans,sum+dp(words,i+1,scores));
        j--;
        while(j>=0)
        {
            map[words[i][j--]]++;
        }        
        return ans;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) 
    {
        for(int i=0;i<size(letters);i++)
        {
            map[letters[i]]++;
        }
     return dp(words,0,score);   
    }
};