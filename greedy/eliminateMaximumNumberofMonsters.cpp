class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> t(dist.size());
        for (int i = 0; i < dist.size(); i++) {
            t[i]=(double)dist[i]/speed[i];
        }
        sort(t.begin(),t.end());
        int time=0;
        while (time<dist.size() && t[time]>time) {
            time++;
        }
        return time;
    }
};