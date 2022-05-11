class Solution {
public:
    unordered_map<int,int>map;
    int integerReplacement(long long n) 
    {
        if(n==1)
            return 0;
        if(map.count(n))
            return map[n];
        if(n%2)return map[n]=1+min(integerReplacement(n-1),integerReplacement(n+1));
        return map[n]=1+integerReplacement(n/2);
    }
};
