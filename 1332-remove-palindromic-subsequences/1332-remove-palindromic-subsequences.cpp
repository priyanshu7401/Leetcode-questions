class Solution {
public:
    int removePalindromeSub(string s) 
    {
    int last=size(s)-1,first=0;
    while(first<last)
    {
        if(s[first++]!=s[last--])
            return 2;
    }
        return 1;
    }
};