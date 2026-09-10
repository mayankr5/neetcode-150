class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stk;
        int sz = temperatures.size();
        vector<int> res;
        for(int i = sz-1; i >= 0; i--){
            int t = 0;
            while(!stk.empty() && stk.top().first <= temperatures[i])
                stk.pop();
            
            if(stk.empty())
                res.push_back(0);
            else
                res.push_back(stk.top().second - i);
            
            stk.push({temperatures[i], i});
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
