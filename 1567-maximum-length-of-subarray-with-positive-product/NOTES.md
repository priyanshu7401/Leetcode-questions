solution 1:
find the lst index where product was negative and  last index where product was zero
```
​
class Solution {
public:
int getMaxLen(vector<int>& nums)
{
int n=size(nums),neg=n,last=-1,pro=1,ans=0;
for(int i=0;i<n;i++)
{
pro*=((nums[i]>0)-(nums[i]<0));
if(pro>0)
{
ans=max(ans,i-last);
}
if(pro<0)
{
neg=min(i,neg);
ans=max(ans,i-neg);
}
if(pro==0)
{
last=i;
neg=n;
pro=1;
}
}
return ans;
}
};
```