class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int n: nums){
            mp[n]++;
        }
        vector<pair<int,int>> v;
        for(auto &it: mp){
            v.push_back(make_pair(it.second, it.first));
        }
        sort(rbegin(v), rend(v));

        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(v[i].second);
        }
        return res;
    }
};
