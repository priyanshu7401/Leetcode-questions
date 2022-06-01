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
​
assume you are at index i: find the total length os + and neg product starting from thix index.
```
int getMaxLen(vector<int>& nums)
{
int n=size(nums),neg=0,pos=0,ans=0;
for(int i=0;i<n;i++)
{
pos++;
if(neg!=0) neg++;
if(nums[i]<0)
{
swap(pos,neg);
}
if(!nums[i])
{
pos=0,neg=0;
}
ans=max(ans,pos);
}
return ans;
}
```