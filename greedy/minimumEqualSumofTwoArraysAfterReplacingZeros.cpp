class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long a=0;
        long long b=0;
        long long z1=0;
        long long z2=0;
        for (auto i : nums1) {
            if (i) {
                a+=i;
            } else {
                z1++;
            }
        }
        for (auto i : nums2) {
            if (i) {
                b+=i;
            } else {
                z2++;
            }
        }
        if (a>b && z2==0) {
            return -1;
        } else if (a>b && (!z1 && z2>a-b)) {
            return -1;
        }
        if (b>a && z1==0) {
            return -1;
        } else if (b>a && (!z2 && z1>b-a)) {
            return -1;
        }
        if (a==b && ((z1==0 && z2>0)||(z2==0 && z1>0))) {
            return -1;
        }
        return max(a+z1,b+z2);
    }
};