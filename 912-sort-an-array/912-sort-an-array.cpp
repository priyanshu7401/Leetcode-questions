class Solution {
public:
    void merge(vector<int>&nums,int start,int end)
    {
        int mid=(start+end)/2;
        
        int i=start,j=mid+1;
        vector<int>vec(end-start+1);
        int k=0;
        while(i<=mid&&j<=end)
        {
            if(nums[i]>=nums[j])
                vec[k++]=nums[j++];
            else
                vec[k++]=nums[i++];
        }
        while(i<=mid)
        {
            vec[k++]=nums[i++];
        }
        while(j<=end)
        {
            vec[k++]=nums[j++];
        }
        for(int i=start;i<=end;i++)nums[i]=vec[i-start];
    }
    void mergesort(vector<int>&nums,int start,int end)
    {
        if(end<=start)
            return;
        int mid=(start+end)/2;
        mergesort(nums,start,mid);
        mergesort(nums,mid+1,end);
        
        merge(nums,start,end);
    }
    vector<int> sortArray(vector<int>& nums) 
    {
        int n=size(nums);
        mergesort(nums,0,n-1);   
        return nums;
    }
};