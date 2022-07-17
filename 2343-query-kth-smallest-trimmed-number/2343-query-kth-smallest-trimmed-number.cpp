template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        vector<pair<string,int>> mapp[110];
        int n=nums[0].size();
        for(int i=n ; i>=1 ; --i) {
            int count=0;
            
            for(auto str: nums) {
                mapp[i].push_back(pair<string,int>{str.substr(n-i), count});
                count++;
            }
            sort(begin(mapp[i]), end(mapp[i]));
        }
        vector<int> v;
        for(auto i: q) {
        
            v.push_back(mapp[i[1]][i[0]-1].second);
        }
        return v;
    }
};