class Solution {
public:
    
    void letterCombinations(string digits,string ans,vector<string>&vec,map<int,string> m) 
    {
    if(digits.size()==0)
    {
       if(ans!=" ") 
        vec.push_back(ans);
        return;
    }
    int num=digits[0]-48;
    string s=m[num];
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        letterCombinations(digits.substr(1),ans+s[i],vec,m);
    }
        
    }
    vector<string> letterCombinations(string digits)
    {
        map<int,string>m;
        m[2]="abc",
        m[3]="def",
        m[4]="ghi",
        m[5]="jkl",
        m[6]="mno",
        m[7]="pqrs",
        m[8]="tuv",
        m[9]="wxyz";
        if(digits.size()==0)
        {
            return {};
        }
        else
        {
        vector<string> vec;
        letterCombinations(digits,"",vec,m);
        return vec;
        }
        
    }
};