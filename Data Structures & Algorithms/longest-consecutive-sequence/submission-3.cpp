class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 0;
        for(int n: nums){
            int num = n;
            if(st.find(n-1) == st.end()){
                while(st.find(num+1) != st.end()){
                    num++;
                }
                res = max(res, num-n+1);
            }
        }
        return res;
    }
};
