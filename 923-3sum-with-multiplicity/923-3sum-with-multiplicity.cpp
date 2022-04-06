class Solution {
public:
    int pairsum(vector<int>&arr,int target,int i,int j)
    {
        int numpairs=0;
    while(i<j) 
    {
        if(arr[i]+arr[j]<target)
        {
            i+=1;
        }
        else if(arr[i]+arr[j]>target)
        {
            j-=1;
        }
        else
        {
           if(arr[i]==arr[j])
           {
               int h=j-i;
               numpairs+=(h*(h+1)/2);
               return numpairs;
           } 
            
            else
           {
            int counti=1;
            int countj=1;
            while(arr[i+1]==arr[i])
            {
                counti+=1;
                i++;
            }
            while(arr[j-1]==arr[j])
            {
                countj+=1;
                j--;
            }
            numpairs+=(counti*countj);
            i++;
            j--;   
           }
        }
    }
        return numpairs;
    }
    int threeSumMulti(vector<int>& arr, int target) 
    {
        sort(arr.begin(),arr.end());
        long long int ans=0;
        int mod=pow(10,9)+7;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
          ans+=pairsum(arr,target-arr[i],i+1,n-1);  
        }
        int ans1=ans%mod;
        return ans1;
    }
};