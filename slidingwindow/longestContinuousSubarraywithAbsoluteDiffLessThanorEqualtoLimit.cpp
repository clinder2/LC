class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int m1 = 0;
        int m2 = 0xefffffff;
        int ans = 1;
        int r = 1;
        int l = 0;
        priority_queue<pair<int,int> > pq1;
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int>>> pq2;
        pair<int,int> a = make_pair(nums[0], 0);
        pq1.push(a);
        pq2.push(a);
        int old = 0;
        while (r<nums.size()) {
            int prev = old;
            int temp = nums[r]>=pq1.top().first ? 1 : 0;
            pair<int,int> a = make_pair(nums[r], r);
            pq1.push(a);
            pq2.push(a);
            while (pq1.size()>0&&pq1.top().second<old) {
                pq1.pop();
            }
            while (pq2.size()>0&&pq2.top().second<old) {
                pq2.pop();
            }
            int diff = abs(pq2.top().first-pq1.top().first);
            //cout<<pq2.top().first<<", "<<pq1.top().first<<"\n";
            if (diff>limit) {
                int f = pq1.top().first-limit;
                if (temp) {
                    while (pq2.size()>0&&pq2.top().first<f) {
                        if (pq2.top().second>=prev) {
                            old = max(old,pq2.top().second+1);
                            //cout<<old<<" a\n";
                        }
                        pq2.pop();
                    }
                } else {
                    f=limit+pq2.top().first;
                    while (pq1.size()>0&&pq1.top().first>f) {
                        if (pq1.top().second>=prev) {
                            old = max(old,pq1.top().second+1);
                        }
                        pq1.pop();
                    }
                }
            }
            r++;
            ans = max(ans, r-old);
        }
        return ans;
    }
};