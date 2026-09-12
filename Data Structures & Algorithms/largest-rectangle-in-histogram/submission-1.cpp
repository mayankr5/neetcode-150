class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> stk;

        for (int i = 0; i < heights.size(); i++) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int h = heights[stk.top()];
                stk.pop();
                int w = stk.empty() ? i : i - stk.top() - 1;
                int area = w * h;
                res = max(res, area);
            }
            stk.push(i);
        }

        int n = heights.size();

        while (!stk.empty()) {
            int h = heights[stk.top()];
            stk.pop();
            int w = stk.empty() ? n : n - stk.top() - 1;
            int area = w * h;
            res = max(res, area);
        }
        return res;
    }
};
