class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int l = 0;
        int r = 0;
        bool left = false;
        while (l<seats.size()&&seats[l]) {
            l++;
            left=true;
        }
        l=max(0,l-1);
        r=l+1;
        int ans = 1;
        bool first = false;
        while (r<seats.size()) {
            while (r<seats.size()&&!seats[r]) {
                r++;
            }
            ans=max(ans,(int)(r-l)/2);
            if (!left&&!first) {
                ans=max(ans,(int)(r-l));
                first=true;
            }
            if (r==seats.size()) {
                ans=max(ans,(int)(r-l-1));
            }
            while (r<seats.size()&&seats[r]) {
                r++;
            }
            l=r-1;
        }
        return ans;
    }
};