class Solution {
public:
    bool hasAllCodes(string s, int k) 
    {
    
    vector<bool>hash(pow(2,k),0);
    int h=0,pp=1;
    string r(rbegin(s),rend(s));
    for(int i=0;i<size(s);i++)
    {
        if(i<k)pp*=2;
        h=(h*2 +r[i]-'0');
        if(i>=k)
            h=h-(r[i-k]-'0')*pp;
        if(i>=k-1)
            hash[h]=1;
    }
    int sum=accumulate(begin(hash),end(hash),0);
    if(sum==pow(2,k))return true;
        return false;
    }
};