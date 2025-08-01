class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int mi = 1000000007;
        for (auto i : time) {
            mi=min(mi, i);
        }
        long long l=0;
        long long r = (long long)mi*totalTrips;
        long long m = (r+l)/2;
        long long ans=r;
        while (l<=r) {
            m = (r+l)/2;
            int count=0;
            int i =0;
            //cout<<l<<", "<<r<<", "<<m<<"\n";
            while (count<totalTrips && i<time.size()) {
                count+=(m/time[i++]);
            }
            if (count>=totalTrips) {
                //ans=min(ans,m);
                ans=m;
                r=m-1;
            } else {
                l=m+1;
            }
            //cout<<l<<", "<<r<<", "<<m<<", "<<count<<"\n";
        }
        return ans;
    }
};