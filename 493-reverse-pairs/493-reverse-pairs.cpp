class Solution {
public:
    int count=0;
    void merge(vector<int>&nums,int start,int end)
    {
        int mid=(start+end)/2;
        vector<int>temp;
        int low=mid+1,index=mid+1;
        for(int i=start;i<=mid;i++)
        {
            while(low<=end && nums[i]>1LL*2*nums[low])low++;
            count+=(low-mid-1);
        
            while(index<=end&&nums[i]>nums[index])
                temp.push_back(nums[index++]);
            temp.push_back(nums[i]);
        }
        while(index<=end)
                temp.push_back(nums[index++]);
        
        for(int i=start;i<=end;i++)
        {
            nums[i]=temp[i-start];
            // cout<<nums[i]<<" ";
        }
        // cout<<endl;
    }
    void mergesort(vector<int>&nums,int start,int end)
    {
        if(end<=start)
            return ;
        
        int mid=(start+end)/2;
        
        mergesort(nums,start,mid);
        mergesort(nums,mid+1,end);
        
        merge(nums,start,end);
    }
    int reversePairs(vector<int>& nums) 
    {
        int n=size(nums);
        mergesort(nums,0,n-1);
        return count;
    }
};