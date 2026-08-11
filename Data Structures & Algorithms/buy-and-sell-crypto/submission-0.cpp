class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minPrice = INT_MAX;
        for(int n: prices){
            if(n < minPrice){
                minPrice = n;
            }
            res = max(res, (n - minPrice));
        }
        return res;
    }
};
