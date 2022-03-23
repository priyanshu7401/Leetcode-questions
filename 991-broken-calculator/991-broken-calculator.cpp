class Solution {
public:
    int brokenCalc(int startValue, int target) 
    {
       int steps=0;
        while(target>startValue)
        {
            if(target%2)
            {
                steps++,target++;
                continue;
            }
            steps++;
            target/=2;
        }
       return steps+startValue-target; 
    }
};