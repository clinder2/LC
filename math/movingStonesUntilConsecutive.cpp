class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> t;
        t.push_back(a);
        t.push_back(b);
        t.push_back(c);
        sort(t.begin(), t.end());
        vector<int> ans;
        if (t[0]+1==t[1] && t[1]+1==t[2]) {
            ans.push_back(0);
            ans.push_back(0);
            return ans;
        }
        if (t[0]+2==t[1]||t[2]-2==t[1]||t[0]+1==t[1]||t[2]-1==t[1]) {
            ans.push_back(1);
        } else {
            ans.push_back(2);
        }
        ans.push_back(t[2]-t[1]-1+t[1]-t[0]-1);
        return ans;
    }
};