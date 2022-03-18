class Solution {
public:
    bool validation(string s,char op)
    {
        if(op==')')
        {
            reverse(begin(s),end(s));
        }
        int bal=0,wild=0;
        for(int i=0;i<size(s);i++)
        {
            
            if(s[i]!='*')
            {
                bal+=(s[i]==op?1:-1);
            }
            else
                wild++;
            if(wild+bal<0)
                return false;
        }
        return wild>=bal;
    }
    bool checkValidString(string s) 
    {
        return validation(s,')')&&validation(s,'(');
    }
};