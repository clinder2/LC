class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int r = intervals[0][1];
        int ans=0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0]<r) {
                ans++;
                r=min(r,intervals[i][1]);
            } else {
                r=intervals[i][1];
            }
        }
        return ans;
    }
};