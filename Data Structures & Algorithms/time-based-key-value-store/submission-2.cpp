class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = store.find(key);

        if(it == store.end())
            return "";

        const auto& values = it->second;

        int lo = 0;
        int hi = values.size() - 1;

        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if(values[mid].first <= timestamp) {
                lo = mid + 1;
            } 
            else {
                hi = mid - 1;
            }
        }

        if(hi < 0)
            return "";

        return values[hi].second;
    }
};