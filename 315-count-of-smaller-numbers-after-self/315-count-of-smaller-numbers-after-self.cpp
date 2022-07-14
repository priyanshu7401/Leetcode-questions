class Solution {
public:
    vector<int>count;
    void merge(vector<int>&nums,vector<int>&index,int start,int end)
    {
        int mid=(start+end)/2;
        int i=start,j=mid+1,countself=0;
        vector<int>merge;
        while(i<=mid && j<=end)
        {
            if(nums[index[i]]>nums[index[j]])
            {
                countself++;
                merge.push_back(index[j]);
                j++;
            }
            else
            {
                count[index[i]]+=countself;
                merge.push_back(index[i]);
                i++;
            }
        }
        while(i<=mid)
        {
            merge.push_back(index[i]);
            count[index[i++]]+=countself;
        }
        while(j<=end)
        {
            merge.push_back(index[j++]);
        }
            
        for(int i=start;i<=end;i++)
            index[i]=merge[i-start];
        // cout<<start<<" "<<end<<endl;
        // for(int i=0;i<size(count);i++)
        //     cout<<count[i]<<" ";
        // cout<<endl;
    }
    void mergesort(vector<int>&nums,vector<int>&index,int start,int end)
    {
        if(end<=start)
            return;
        int mid=(start+end)/2;
        mergesort(nums,index,start,mid);
        mergesort(nums,index,mid+1,end);
        
        merge(nums,index,start,end);
    }
    vector<int> countSmaller(vector<int>& nums) 
    {
        int n=size(nums);
        vector<int>index(n);
        count.resize(n,0);
        for(int i=0;i<n;i++)
            index[i]=i;
        mergesort(nums,index,0,n-1);  
        return count;
    }
};