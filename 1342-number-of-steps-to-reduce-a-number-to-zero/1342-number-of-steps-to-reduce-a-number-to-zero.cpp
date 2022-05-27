class Solution {
public:
    int numberOfSteps(int num) 
    {
    if(num==0||num==1)
        return num;
    // cout<<num<<" ";
    return 1+num%2+numberOfSteps(num/2);    
    }
};