class Solution {
public:
    int parent[100001]={0};   
    int find(int parent[],int i)
    {
        if(parent[i]==i)
            return i;
        return parent[i]=find(parent,parent[i]);
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) 
    {
        int n=vals.size(),ans=n;
        vector<vector<int>>component(n,vector<int>(2,-1));
        auto mycmp=[&](vector<int>&a,vector<int>&b){
            return max(vals[a[0]],vals[a[1]])< max(vals[b[0]],vals[b[1]]);
        };
        
        sort(begin(edges),end(edges),mycmp);
        
        for(int i=0;i<n;i++)parent[i]=i;

        int maxi=-1;
        for(auto vec:edges)
        {
                maxi=max(vals[vec[0]],vals[vec[1]]);
            
                int par0=find(parent,vec[0]);
                int par1=find(parent,vec[1]);
                
                if(component[par0][1]<maxi)component[par0][0]=(vals[par0]==maxi),component[par0][1]=maxi;
                if(component[par1][1]<maxi)component[par1][0]=(vals[par1]==maxi),component[par1][1]=maxi;
                ans+=component[par0][0]*component[par1][0];
                component[par1][0]=component[par0][0]+component[par1][0];
                
                parent[par0]=par1;
         
        }
        
        return ans;
    }
};