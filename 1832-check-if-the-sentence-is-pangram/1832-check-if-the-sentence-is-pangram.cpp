class Solution {
public:
    bool checkIfPangram(string sentence) 
    {
        int ans=0;
        for(int i=0;i<sentence.size();i++)
            ans|=(1<<(sentence[i]-'a'));
        return ans==pow(2,26)-1;
    }
};