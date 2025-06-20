class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int a = 0;
        int prev = nums[0];
        if (nums[0] != 1) {
            int i = 1;
            a=1;
            prev+=1;
            while (2*i<nums[0]) {
                i*=2;
                a++;
                prev+=i;
            }
        }
        for (int i = 1; i < nums.size() && prev<n; i++) {
            if (nums[i]-prev>1) {
                int b = prev+1;
                a++;
                prev=2*b-1;
                if (prev>=n) {
                    return a;
                }
                while (prev<nums[i]-1) {
                    a++;
                    b*=2;
                    prev=2*b-1;
                    if (prev>=n) {
                        return a;
                    }
                }
            }
            prev+=nums[i];
        }
        if (prev<n) {
            a++;
            long b = prev+1;
            while (2*b-1<n) {
                a++;
                b*=2;
                //cout<<b<<"\n";
            }
        }
        return a;
    }
};