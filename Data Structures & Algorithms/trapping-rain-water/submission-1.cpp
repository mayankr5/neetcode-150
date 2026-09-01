class Solution {
public:
    int trap(vector<int>& height) {
        int topPt = max_element(height.begin(), height.end()) - height.begin();
        int st = 0, en = height.size()-1;
        int totalWater = 0;
        int curr = 0;
        for(int i = 0; i <= topPt; i++){
            if(height[i] >= height[st]){
                totalWater += curr;
                curr = 0;
                st = i;
                continue;
            }
            curr += height[st] - height[i];
        }

        for(int i = height.size()-1; i >= topPt; i--){
            if(height[i] >= height[en]){
                totalWater += curr;
                curr = 0;
                en = i;
                continue;
            }
            curr += height[en] - height[i];
        }
        return totalWater;
    }
};
