#define ll long long
class Solution {
public:
    long long countVowels(string word) 
    {
    ll last=0,prefix=0,n=size(word);
    string vowel="aeiou";
    for(int i=0;i<n;i++)
    {
        if(vowel.find(word[i])!=string::npos)last=(last+(i+1));
        prefix+=last;
    }
        return prefix;
    }
};