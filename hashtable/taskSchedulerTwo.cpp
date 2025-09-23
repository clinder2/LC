class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<long long,long long> m;
        long long ans=1;
        int i = 0;
        while (i < tasks.size()) {
            long long t = tasks[i];
            if (m[t]>ans) {
                ans=m[t];
            } else {
                m[t]=ans+space+1;
                ans++;
                i++;
            }
            //cout<<ans<<" ";
            //ans++;
        }
        return ans-1;
    }
};