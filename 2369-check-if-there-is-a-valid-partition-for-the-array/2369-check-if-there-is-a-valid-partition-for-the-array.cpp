int dp[100005];
class Solution {
public:
    bool check(vector<int> &a, int i) {
        if(i == a.size()) {
            return 1;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        bool a1 = (i<=a.size()-2 ? (a[i]==a[i+1] and check(a, i+2)) : 0);
        bool a2 = (i<=a.size()-3 ? (a[i]==a[i+1] and a[i+1]==a[i+2] and check(a, i+3)) : 0);
        bool a3 = (i<=a.size()-3 ? (a[i]+1==a[i+1] and a[i+1]+1==a[i+2] and check(a, i+3)) : 0);
        return dp[i] = (a1 or a2 or a3 ? 1 : 0);
    }
    bool validPartition(vector<int>& a) {
        // The subarray consists of exactly 2 equal elements. For example, the subarray [2,2] is good.
        // The subarray consists of exactly 3 equal elements. For example, the subarray [4,4,4] is good.
        // The subarray consists of exactly 3 consecutive increasing elements, that is, the difference between adjacent elements is 1. For example, the subarray [3,4,5] is good, but the subarray [1,3,5] is not.
        if(a.size() == 2) {
            return a.front() == a.back();
        }
        memset(dp, -1, sizeof(dp));
        return check(a, 0);
    }
};