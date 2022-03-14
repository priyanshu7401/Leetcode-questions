#define all(x)  x.begin(),x.end()
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) 
    {
    int maxi=*max_element(all(nums));
    int mini=*min_element(all(nums));    
    return max((maxi-mini-2*k),0);    
    }
};