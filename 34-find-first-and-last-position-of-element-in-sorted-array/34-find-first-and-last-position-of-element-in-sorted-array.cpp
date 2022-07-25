class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) 
    {
    if(!a.size())
        return {-1,-1};
    int n=a.size();
    vector<int>ans(2,-1);
    int i=0,j=n-1;
    while(i<j)
    {
        int mid=(i+j)/2;
        if(a[mid]<target)
            i=mid+1;
        else 
            j=mid;
    }
    if(a[i]!=target)
        return ans;
    ans[0]=i;
    j=n-1;
    while(i<j)
    {
        int mid=(i+j)/2+1;
        if(a[mid]>target)
            j=mid-1;
        else
            i=mid;
    }
    if(a[j]!=target)
        return {ans[0],ans[0]};
    ans[1]=j;
    return ans;
        
    }
    
};
// vector<int> searchRange(int A[], int n, int target) {
//     int i = 0, j = n - 1;
//     vector<int> ret(2, -1);
//     // Search for the left one
//     while (i < j)
//     {
//         int mid = (i + j) /2;
//         if (A[mid] < target) i = mid + 1;
//         else j = mid;
//     }
//     if (A[i]!=target) return ret;
//     else ret[0] = i;
    
//     // Search for the right one
//     j = n-1;  // We don't have to set i to 0 the second time.
//     while (i < j)
//     {
//         int mid = (i + j) /2 + 1;	// Make mid biased to the right
//         if (A[mid] > target) j = mid - 1;  
//         else i = mid;				// So that this won't make the search range stuck.
//     }
//     ret[1] = j;
//     return ret; 
// }