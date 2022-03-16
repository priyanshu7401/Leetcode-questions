class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int i=0,j=0,n=size(pushed);
        stack<int>s;
        for(int i=0;i<size(pushed);i++)
        {
            s.push(pushed[i]);
            while(!s.empty()&&j<n&&s.top()==popped[j])
            {
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};