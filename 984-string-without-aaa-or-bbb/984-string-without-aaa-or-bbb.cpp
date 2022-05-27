class Solution {
public:
    string strWithout3a3b(int a, int b) 
    {
    string s="";
    int i=0;
    while(a||b)
    {
        if(i>1&&s[i-1]=='a'&&s[i-2]=='a')
        {
            s+='b';
            b--;
        }
        else if(i>1&&s[i-1]=='b'&&s[i-2]=='b')
        {
            s+='a';
            a--;
        }
        else if(a>=b)
        {
            s+='a';
            a--;
        }
        else
        {
            s+='b';
            b--;
        }
          i++;
    }
        return s;
    }
};

