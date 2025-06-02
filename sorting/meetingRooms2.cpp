bool compare(vector<int>& a, vector<int>& b) {
    return a[0]<b[0];
}
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size()==1) {
            return 1;
        }
        sort(intervals.begin(), intervals.end(), compare);
        int start = intervals[0][0];
        int end = intervals[0][1];
        int ans = 1;
        vector<vector<int>> temp;
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(end);
        for (int i = 1; i < intervals.size(); i++) {
            //cout<<pq.top()<<"\n";
            if (intervals[i][0]>=pq.top()) {
                pq.pop();
                //pq.push(intervals[i][1]);
            } else {
                ans++;
                //pq.push(intervals[i][1]);
            }
            pq.push(intervals[i][1]);
        }
        return ans;
    }
};