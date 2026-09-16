class Solution {
public:
    bool willEat(int k, vector<int> &piles, int h){
        int timeReq = 0;
        for(int p: piles){
            timeReq += (p/k) + (p%k ? 1 : 0);
        }
        return timeReq <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int res = INT_MAX;
        int mn = 1, mx = *max_element(piles.begin(), piles.end());
        while(mn <= mx){
            int mid = mn + (mx-mn)/2;
            if(willEat(mid, piles, h)){
                res = min(res, mid);
                mx = mid - 1;
            }else
                mn = mid + 1;
        }
        return res;
    }
};
