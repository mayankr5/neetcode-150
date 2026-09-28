class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        int expSum = (nums.size() * (nums.size()+1))/2;
        return expSum-sum;
    }
};
