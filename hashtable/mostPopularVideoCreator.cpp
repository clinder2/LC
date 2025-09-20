class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string, long long> c_count;
        map<string, pair<string, int>> c_vid;
        long long m=-1;
        for (int i = 0; i < creators.size(); i++) {
            c_count[creators[i]]+=views[i];
            if (c_count[creators[i]]>m) {
                m=c_count[creators[i]];
            }
            if (c_vid[creators[i]].first=="") {
                c_vid[creators[i]]=make_pair(ids[i], views[i]);
            }
            if (views[i]>c_vid[creators[i]].second) {
                c_vid[creators[i]]=make_pair(ids[i], views[i]);
            } else if (views[i]==c_vid[creators[i]].second && ids[i]<c_vid[creators[i]].first) {
                c_vid[creators[i]]=make_pair(ids[i], views[i]);
            }
        }
        vector<vector<string>> ans;
        for (auto p : c_count) {
            if (p.second==m) {
                ans.push_back({p.first, c_vid[p.first].first});
            }
        }
        return ans;
    }
};