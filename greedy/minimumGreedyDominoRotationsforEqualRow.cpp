class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> t(6);
        vector<int> b(6);
        vector<int> over(6);
        for (int i = 0; i < bottoms.size(); i++) {
            t[tops[i]-1]++;
            b[bottoms[i]-1]++;
            if (tops[i]==bottoms[i]) {
                over[tops[i]-1]++;
            }
        }
        int ans=100000;
        for (int i = 0; i < 6; i++) {
            if (t[i]+b[i]-over[i]==tops.size()) {
                ans=min(ans, min(t[i],b[i])-over[i]);
            }
        }
        return ans<100000 ? ans : -1;
    }
};