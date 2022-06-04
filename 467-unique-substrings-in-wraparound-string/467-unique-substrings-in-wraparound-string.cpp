class Solution {
public:
    int findSubstringInWraproundString(string p) 
    {
       vector<int>ans(26,0);
       int maxLen=1;
       for(int i=0;i<size(p);i++)
       {
           if(i>0&&(p[i]-p[i-1]==1||p[i]-p[i-1]==-25))
           {
               maxLen++;
           }
           else
               maxLen=1;
           ans[p[i]-'a']=max(ans[p[i]-'a'],maxLen);
       }
        
       return accumulate(begin(ans),end(ans),0);
    }
};

/*
"abcdefghijklmnopqrstuvwxyz"
   
abc
*/