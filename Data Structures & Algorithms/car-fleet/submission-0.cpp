class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pos;
        for(int i = 0; i < position.size(); i++){
            pos.push_back(make_pair(position[i], speed[i]));
        }
        sort(pos.begin(), pos.end());
        stack<double>stk;
        vector<double> time;
        for(int i = 0; i < position.size(); i++){
            double t = (double)(target-pos[i].first)/pos[i].second;
            while(!stk.empty() && stk.top() <= t)
                stk.pop();
            stk.push(t);
        }
        return stk.size();
    }
};
