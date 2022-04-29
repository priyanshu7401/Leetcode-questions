class Solution {
public:
    bool dfs(vector<vector<int>>&heights,int i,int j,int prev,vector<vector<int>>&visited,int limit)
    {
        int m=heights.size();
        int n=heights[0].size();
        
        if(i<0||i>=m|j<0||j>=n||visited[i][j])
            return false;
        
        if(abs(heights[i][j]-prev)>limit)return false;
        visited[i][j]=1;
        
        if(i==m-1&&j==n-1)return true;
        

        
        bool ans1=dfs(heights,i+1,j,heights[i][j],visited,limit);
        bool ans2=dfs(heights,i,j+1,heights[i][j],visited,limit);
        bool ans3=dfs(heights,i-1,j,heights[i][j],visited,limit);
        bool ans4=dfs(heights,i,j-1,heights[i][j],visited,limit);
        
        int ans=ans1|ans2|ans3|ans4;
        
        return ans;
            
    }
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int m=heights.size();
        int n=heights[0].size();
        
        int low=0,high=1e6;
        while(low<high)
        {
            vector<vector<int>>visited(m,vector<int>(n,0));
            int mid=(low+high)/2;
            if(dfs(heights,0,0,heights[0][0],visited,mid))
                high=mid;
            else
                low=mid+1;
            // cout<<low<<" "<<high<<endl;   
        }
       return low;
    }
};