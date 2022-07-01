class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
    string ans="";
    for(int j=0;j<size(strs[0]);j++)
    {
        char ch=strs[0][j];
        for(int i=0;i<size(strs);i++)
        {
            if(strs[i][j]=='\0'||strs[i][j]!=ch)
            {
                return ans;
            }
            
        }        
        ans+=ch;
    }
        return ans;
    }
};