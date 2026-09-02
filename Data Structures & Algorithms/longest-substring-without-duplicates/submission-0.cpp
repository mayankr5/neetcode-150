class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0 || s.size() == 1)
            return s.size();

        int res = 0, curr = 0, lst = 0;
        vector<int> freq(256, -1);
        for(int i = 0; i < s.size(); i++){
            if(freq[s[i]] != -1){
                while(freq[s[i]] != -1){
                    freq[s[lst]] = -1;
                    lst++; curr--;
                }
            }
            freq[s[i]] = i;
            res = max(res, curr);
            curr++;
        }
        return res+1;
    }
};
