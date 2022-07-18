class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
    {
        int m=size(matrix),n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        int res=0;
        for(int col=0;col<n;col++)
        {
            for(int j=col;j<n;j++)
            {
                 unordered_map<int,int>map;
                 map[0]=1;
                 int cur=0;
                 for(int row=0;row<m;row++)
                 {
                     cur+=matrix[row][j]-(col>0?matrix[row][col-1]:0);
                     if(map.count(cur-target))
                         res+=map[cur-target];
                     map[cur]++;
                 }
            }
        }
        return res;
    }
};

//     int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
//         int res = 0, m = A.size(), n = A[0].size();
//         for (int i = 0; i < m; i++)
//             for (int j = 1; j < n; j++)
//                 A[i][j] += A[i][j - 1];

//         unordered_map<int, int> counter;
//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 counter = {{0,1}};
//                 int cur = 0;
//                 for (int k = 0; k < m; k++) {
//                     cur += A[k][j] - (i > 0 ? A[k][i - 1] : 0);
//                     res += counter.find(cur - target) != counter.end() ? counter[cur - target] : 0;
//                     counter[cur]++;
//                 }
//             }
//         }
//         return res;
//     }