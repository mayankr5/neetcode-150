class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<pair<int,int>> arr;
        // for(int i = 0; i < nums.size(); i++){
        //     arr.push_back({nums[i], i});
        // }

        // sort(begin(arr), end(arr));

        // vector<int> res;
        // int i = 0, j = nums.size()-1;
        // while(i < j){
        //     int cur = arr[i].first + arr[j].first;
        //     if (cur == target) {
        //         return {min(arr[i].second, arr[j].second),
        //                 max(arr[i].second, arr[j].second)};
        //     } else if (cur < target) {
        //         i++;
        //     } else {
        //         j--;
        //     }
        // }

        // return res;

        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if(mp.find(diff) != mp.end()){
                return {mp[diff], i};
            }

            mp.insert({nums[i], i});
        }

        return {};
    }
};
