class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        vector<vector<int>> win;
        for (auto l : lights) {
            vector<int> t = {l[0]-l[1], l[0]+l[1]};
            win.push_back(t);
        }
        sort(win.begin(), win.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(win[0][1]);
        int ma=0;
        int index=win[0][0];
        for (int i = 1; i < win.size(); i++) {
            if (pq.size() && pq.top()<win[i][0]) {
                pq.pop();
                pq.push(win[i][1]);
            } else {
                pq.push(win[i][1]);
                if (pq.size()>ma) {
                    ma=pq.size();
                    index=win[i][0];
                    //cout<<index<<" ";
                }
            }
        }
        return index;
    }
};