class Solution {
public:
    string next_permutation(string s)
    {
        if(s.size()==1)
            return s;
        int n=s.size(),i=n-1;
        while(i>1&&s[i]<=s[i-1])i--;
        int j=i;
        while(j<n&&s[i-1]<s[j])j++;
        swap(s[i-1],s[j-1]);
        reverse(begin(s)+i,end(s));
        return s;
    }
    
    int nextGreaterElement(int n) 
    {
    string s=to_string(n);
    int num=stol(next_permutation(s));
    if(num<=n)return -1;
    return  num;
    }
};