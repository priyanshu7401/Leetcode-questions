class Solution {
public:
    int minSetSize(vector<int>& arr)
    {
    sort(arr.begin(),arr.end());
    vector<int>vec;
    int count=1;
    int len=arr.size();
    for(int i=1;i<len;i++)
    {
        if(arr[i]==arr[i-1])
        {
            count++;
        }
        else
        {
            vec.push_back(count);
            count=1;
        }
    }
    vec.push_back(count);
    sort(vec.begin(),vec.end(),greater<int>());
    int newlen=len;
    int i=0;
    while(newlen>len/2)
    {
        newlen-=vec[i];
        i++;
    }
        return i;
    }
};