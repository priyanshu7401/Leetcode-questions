class Solution {
public:
    vector<bool>visited;
    void dfs(vector<vector<int>>&rooms,int start)
    {
        if(visited[start])
            return;
        visited[start]=1;
        for(int i=0;i<size(rooms[start]);i++)
        {
            dfs(rooms,rooms[start][i]);
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
         int n=rooms.size();
         visited.resize(n,0); 
         dfs(rooms,0);
         return accumulate(begin(visited),end(visited),0)==n;
    }
};