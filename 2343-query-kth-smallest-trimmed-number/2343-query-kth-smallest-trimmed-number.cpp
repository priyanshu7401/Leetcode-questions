class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        for (vector<int>& p : queries) {
            vector<pair<string, int>> tmp;
            for (int i=0; i<nums.size(); i++) tmp.push_back(make_pair(nums[i].substr(nums[i].size()-p[1]), i));
            sort(tmp.begin(), tmp.end());
            res.push_back(tmp[p[0]-1].second);
        }
        return res;
    }
};