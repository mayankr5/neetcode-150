class Solution {
public:

    string encode(vector<string>& strs) {
        string enc = "";
        for(string s: strs){
            for(char c: s){
                if(c == '/')
                    enc += '/';
                enc += c;
            }
            enc += '/';
        }
        return enc;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        string t = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '/'){
                if(++i == s.size() || s[i] != '/' || (s[i] == '/' && i == s.size()-1)){
                    strs.push_back(t);
                    t = "";
                    if(i == s.size()-1)
                        strs.push_back(t);
                }
            }
            t += s[i];
        }
        return strs;
    }
};
