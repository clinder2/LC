class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int r = 0;
        int l = 1;
        long long t=(long long)m*k;
        if (t>bloomDay.size()) {
            return -1;
        }
        for (auto i : bloomDay) {
            r=max(r,i);
        }
        int ans=r;
        while (l<=r) {
            int mi = (l+r)/2;
            int temp=0;
            int prev=0;
            for (auto i : bloomDay) {
                if (i<=mi) {
                    prev++;
                } else {
                    prev=0;
                }
                if (prev==k) {
                    prev=0;
                    temp++;
                }
            }
            if (prev==k) {
                temp++;
            }
            //cout<<mi<<", "<<temp<<"\n";
            if (temp>=m) {
                ans=min(ans,mi);
                r=mi-1;
            } else {
                l=mi+1;
            }
        }
        return ans;
    }
};