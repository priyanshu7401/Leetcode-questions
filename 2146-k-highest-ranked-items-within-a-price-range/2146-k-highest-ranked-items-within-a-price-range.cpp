int dir[]={-1,0,1,0,-1};
class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) 
    {
        int m=size(grid),n=size(grid[0]);
        vector<vector<int>>store;
        queue<vector<int>>q;
        q.push(start);
        int dist=0,low=pricing[0],high=pricing[1];
        if(grid[start[0]][start[1]]>=low&&grid[start[0]][start[1]]<=high)
        {
            store.push_back({start[0],start[1],0,grid[start[0]][start[1]]});
        }
        while(!q.empty())
        {
            int len=q.size();
            for(int i=0;i<len;i++)
            {
            vector<int>top=q.front();
            q.pop();
            grid[top[0]][top[1]]=0;
            for(int k=0;k<4;k++)
            {
                int I=top[0]+dir[k];
                int J=top[1]+dir[k+1];
                
                if(I<0||I>=m||J<0||J>=n||!grid[I][J])continue;
                
                // cout<<I<<" "<<J<<endl;   
                if(grid[I][J]>=low&&grid[I][J]<=high)
                {
                    store.push_back({I,J,dist+1,grid[I][J]});
                }
                grid[I][J]=0;
                q.push({I,J});
                
            }
            }
            dist+=1;
        }
        
        auto mycmp= [&](vector<int>&a,vector<int>&b)
        {
            if(a[2]!=b[2])
                return a[2]<b[2];
            else if (a[3]!=b[3])
                return a[3]<b[3];
            else if(a[0]!=b[0])
                return a[0]<b[0];
            else
                return a[1]<b[1];
        };
        sort(begin(store),end(store),mycmp);
        vector<vector<int>>ans;
        int len=size(store);
        for(int i=0;i<min(k,len);i++)
        {
            ans.push_back({store[i][0],store[i][1]});
        }
        return ans;
    }
};