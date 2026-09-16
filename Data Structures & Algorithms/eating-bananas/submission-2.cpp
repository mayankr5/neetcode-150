class Solution {
public:
    bool willEat(int k, vector<int>& piles, int h) {
        long long hours = 0;
        for (int p : piles) {
            hours += (p + k - 1) / k;
            if (hours > h)
                return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (willEat(mid, piles, h)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
