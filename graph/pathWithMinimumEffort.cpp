class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        map<int, pair<int, int>> m;
        int r = heights.size();
        int c = heights[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        while (pq.size()>0) {
            vector<int> curr = pq.top();
            pq.pop();
            int v = curr[0];
            int r2 = curr[1];
            int c2 = curr[2];
            int old = heights[r2][c2];
            if (old==-1) {
                continue;
            }
            //cout<<v<<", "<<curr[1]<<", "<<curr[2]<<", "<<heights[r2][c2]<<"\n";
            if (r2==r-1 && c2==c-1) {
                return v;
            }
            if (r2-1>=0 && heights[r2-1][c2]!=-1) {
                pq.push({max(v, abs(heights[r2-1][c2]-old)), r2-1, c2});
                //pq.push({abs(heights[r2-1][c2]-old), r2-1, c2});
            }
            if (r2+1<r && heights[r2+1][c2]!=-1) {
                pq.push({max(v,abs(heights[r2+1][c2]-old)), r2+1, c2});
                //pq.push({abs(heights[r2+1][c2]-old), r2+1, c2});
            }
            if (c2-1>=0 && heights[r2][c2-1]!=-1) {
                pq.push({max(v,abs(heights[r2][c2-1]-old)), r2, c2-1});
                //pq.push({abs(heights[r2][c2-1]-old), r2, c2-1});
            }
            if (c2+1<c && heights[r2][c2+1]!=-1) {
                pq.push({max(v,abs(heights[r2][c2+1]-old)), r2, c2+1});
                //pq.push({abs(heights[r2][c2+1]-old), r2, c2+1});
            }
            heights[curr[1]][curr[2]] = -1;
        }
        return 0;
    }
};