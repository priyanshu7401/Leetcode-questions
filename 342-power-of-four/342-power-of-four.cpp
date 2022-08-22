class Solution {
public:
    bool isPowerOfFour(int n) 
    {
    return (n>0)&&(pow(4,round(log(n)/log(4)))==n)?true:false;    
    }
};