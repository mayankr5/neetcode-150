class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fst = 0, slw = 0;
        do {
            slw = nums[slw];
            fst = nums[nums[fst]];
        }while(fst != slw);
        fst = 0;
        while(fst != slw){
            fst = nums[fst];
            slw = nums[slw];
        }
        return slw;
    }
};
