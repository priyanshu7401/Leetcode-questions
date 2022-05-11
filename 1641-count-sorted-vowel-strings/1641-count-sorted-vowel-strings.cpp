class Solution {
public:
    vector<char>vowel={'a','e','i','o','u'};
    int helper(int n,int i)
    {
        if(n==0)
            return 1;
        if(i==size(vowel))
            return 0;
        return helper(n-1,i)+helper(n,i+1);
    }
    int countVowelStrings(int n) 
    {
        return helper(n,0);
    }
};
