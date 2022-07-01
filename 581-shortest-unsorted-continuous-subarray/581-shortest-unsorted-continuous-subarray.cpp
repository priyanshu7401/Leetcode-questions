class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
    int i=0,n=size(nums),j=n-1;
    vector<int>temp=nums;
    sort(begin(temp),end(temp));
    while(i<n && temp[i]==nums[i])i++;
    while(j>=0 && temp[j]==nums[j])j--;
    return max(j-i+1,0);
    }
};