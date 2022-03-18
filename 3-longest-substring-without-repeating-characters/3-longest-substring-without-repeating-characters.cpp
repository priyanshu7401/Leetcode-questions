class Solution {
public:
    
    int lengthOfLongestSubstring(string s) 
    {
        int n=size(s);
        vector<int>vec(256,0);
        int start=0,ans=0;
        for(int i=0;i<n;i++)
        {
            vec[s[i]]++;
            while(start<i&&vec[s[i]]>1)
            {
                vec[s[start]]--;
                start++;
            }
            ans=max(ans,i-start+1);
        }
        return ans;
    }
};