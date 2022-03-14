#define ll long long
class Solution {
public:
    long long countVowels(string word) 
    {
    ll last=0,prefix=0,n=size(word);
    for(ll i=0;i<n;i++)
    {
        if(string("aeiou").find(word[i])!=string::npos)
            prefix+=(n-i)*(i+1);
    }
        return prefix;
    }
};