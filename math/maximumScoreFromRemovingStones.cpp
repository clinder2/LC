class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> t;
        t.push_back(a);
        t.push_back(b);
        t.push_back(c);
        sort(t.begin(),t.end());
        int ans=0;
        if (t[0]+t[1]>t[2]) {
            ans+=(t[0]+t[1]-t[2])/2;
            return ans+t[2];
        }
        return t[1]+t[0];
    }
};