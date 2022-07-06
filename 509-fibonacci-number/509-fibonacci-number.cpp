class Solution {
public:
    int f(int n)
    {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        return f(n-1)+f(n-2); 
    }
    
    
    int fib(int n) 
    {
    if(n==0)return 0;
    int a=0,b=1;
    for(int i=2;i<=n;i++)
    {
        int c=a+b;
        a=b;
        b=c;
    }
    return b;
    }
};