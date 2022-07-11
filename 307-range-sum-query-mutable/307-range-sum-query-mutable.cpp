class NumArray {
public:
    int RSB(int i)
    {

        return i&(-i);
    }
    vector<int>tree;
    vector<int>nums;
    int n;
    NumArray(vector<int>& nums) 
    {
        n=size(nums)+1;//for one indexing
        nums.insert(nums.begin(),0);//make nums one indexed.
        this->nums=nums;
        this->tree=nums;
        for(int i=1;i<n;i++) 
        {

            int parent=i+RSB(i);
            if(parent<n)tree[parent]+=tree[i];
        }
    }
    
    void update(int index, int val) 
    {
        index+=1;//for one indexing
        int x=val-nums[index];
        nums[index]=val;
        while(index<n)
        {
            tree[index]+=x;
            index+=RSB(index);
        }
    }
    int prefixsum(int i)
    {
        int ans=0;
        while(i!=0)
        {
            ans+=tree[i];
            i-=RSB(i);
        }
        return ans;
    }
    
    int sumRange(int left, int right) 
    {
        return prefixsum(right+1)-prefixsum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */