class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
    int n=size(nums);
    stack<int>st;
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++)nums.push_back(nums[i]);
    for(int i=0;i<2*n;i++)
    {
        while(!st.empty()&&nums[st.top()]<nums[i])
        {
            ans[st.top()%n]=nums[i];
            st.pop();
        }
        st.push(i);
    }
        return ans;
    }
};