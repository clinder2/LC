class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        vector<int> a={0,0,0,0,0};
        int count=0;
        int ans=0;
        for (auto c : croakOfFrogs) {
            if (c=='c') {
                a[0]++;
                count++;
            } else if (c=='r') {
                if (a[0]) {
                    a[0]--;
                    a[1]++;
                } else {
                    return -1;
                }
            } else if (c=='o') {
                if (a[1]) {
                    a[1]--;
                    a[2]++;
                } else {
                    return -1;
                }
            } else if (c=='a') {
                if (a[2]) {
                    a[2]--;
                    a[3]++;
                } else {
                    return -1;
                }
            } else if (c=='k') {
                if (a[3]) {
                    a[3]--;
                    count--;
                } else {
                    return -1;
                }
            }
            ans=max(ans,count);
        }
        for (auto i : a) {
            if (i) {
                return -1;
            }
        }
        return ans;
    }
};