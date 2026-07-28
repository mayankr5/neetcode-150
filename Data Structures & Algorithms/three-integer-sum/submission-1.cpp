class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> temp;
        sort(begin(nums), end(nums));
        for(int i = 0; i < nums.size()-2; i++){
            int st = i+1, en = nums.size()-1;
            while(st < en){
                int sum = nums[i] + nums[st] + nums[en];
                if(!sum){
                    vector<int> tri = {nums[i], nums[st], nums[en]};
                    temp.insert(tri);
                    st++; en--;
                }
                else if(sum > 0)
                    en--;
                else
                    st++;
            }
        }
        vector<vector<int>> res;
        for(auto it: temp)
            res.push_back(it);
        return res;
    }
};
