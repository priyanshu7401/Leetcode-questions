class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) 
    {
    vector<int>pos={a,b,c};
    sort(begin(pos),end(pos));
    int mini =INT_MAX;
    if(pos[2]-pos[1]==2||pos[1]-pos[0]==2)
        mini=1;
    return {min(min(pos[1]-pos[0]-1,1)+min(pos[2]-pos[1]-1,1),mini),pos[2]-pos[0]-2};    
    }
};