class Solution {
public:
    bool validation(string s,string locked ,char op)
    {
        if(op==')')
        {
            reverse(begin(s),end(s));
            reverse(begin(locked),end(locked));
        }
        int wild=0,bal=0;
        for(int i=0;i<s.size();i++)
        {
            if(locked[i]=='1')
                bal+=(s[i]==op?1:-1);
            else 
                wild+=1;
            if(wild+bal<0)
                return false;
        }
        return bal<=wild;
    }
    bool canBeValid(string s, string locked) 
    {
        return size(s)%2==0&&validation(s,locked,'(')&&validation(s,locked,')');
    }
};