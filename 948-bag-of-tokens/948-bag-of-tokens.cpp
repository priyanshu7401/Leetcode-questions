class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        int score=0,n=size(tokens);
        sort(begin(tokens),end(tokens));
        int i=0,j=n-1;
        while(i<=j)
        {
            if(power>=tokens[i])
            {
                score++;
                power-=tokens[i++];
            }
            else if(power<tokens[i])
            {
                if(score&&(i!=j))
                {
                    score--;
                    power+=tokens[j];
                    j--;
                }
                else
                {
                    return score;
                }   
            }
        }
        return score;
    }
};