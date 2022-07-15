class Solution {
public:
    int count=0;
    int lower=0;
    int upper=0;
    void merge(vector<long long>&sum,int start,int end)
    {
        int mid=(start+end)/2;
        
        int low=mid+1,high=mid+1,index=mid+1;
        vector<long long>temp;
        for(int i=start;i<=mid;i++)
        {
            while(low<=end&&sum[low]-sum[i]<lower)low++;
            while(high<=end&&sum[high]-sum[i]<=upper)high++;
            
            count+=high-low;
            
            while(index<=end&&sum[index]<sum[i])
                temp.push_back(sum[index++]);
            
            temp.push_back(sum[i]);
        }
        while(index<=end)
             temp.push_back(sum[index++]);
        for(int i=start;i<=end;i++)
            sum[i]=temp[i-start];
    }
    void mergesort(vector<long long>&sum,int start,int end)
    {
        if(end<=start)
        {
            return;
        }
        int mid=(start+end)/2;
        
        mergesort(sum,start,mid);
        mergesort(sum,mid+1,end);
        
        merge(sum,start,end);
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) 
    {
        this->lower=lower;
        this->upper=upper;
        int n=size(nums);
        
        vector<long long>sum(n+1,0);
        
        for(int i=0;i<n;i++)
            sum[i+1]=sum[i]+nums[i];
        
        mergesort(sum,0,n);
        return count;
    }
};