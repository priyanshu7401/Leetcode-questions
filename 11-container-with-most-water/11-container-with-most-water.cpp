class Solution {
public:
    int maxArea(vector<int>& height) 
    {
    int i=0,j=height.size()-1;
    int maxi=0;
    
    while(j>i)
    {
    int temp=min(height[i],height[j]);
    int newans=temp*(j-i);
    maxi=max(maxi,newans);
    height[i]>=height[j]?j--:i++;

    }
        return maxi;
    }
};