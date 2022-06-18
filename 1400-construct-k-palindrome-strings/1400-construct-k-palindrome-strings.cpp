class Solution {
public:
    bool canConstruct(string s, int k) 
    {
         vector<int>vec(26,0);
         for(int i=0;i<size(s);i++)
         {
             vec[s[i]-'a']++;
         }
        int countodd=0,counteven=0;
        for(int i=0;i<26;i++)
        {
            if(vec[i]%2)countodd++;
            counteven+=vec[i]/2;
        }

        return countodd<=k&&s.size()>=k;
    }
};