class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cntZero = 0;
        int totalProd = 1;
        for(int n: nums){
            if(n == 0){
                cntZero++;
                continue;
            }
            totalProd *= n;
        }
        if(cntZero > 1){
            return vector<int>(nums.size(), 0);
        }

        vector<int> res;
        for(int n: nums){
            if(cntZero){
                if(!n){
                    res.push_back(totalProd);
                }else{
                    res.push_back(0);
                }
            }
            else
                res.push_back(totalProd/n);
        }
        return res;
    }
};
