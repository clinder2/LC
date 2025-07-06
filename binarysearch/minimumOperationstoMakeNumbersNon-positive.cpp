class Solution {
public:
    int minOperations(vector<int>& nums, int x, int y) {
        if (nums.size()==1) {
            return ceil((double)nums[0]/x);
        }
        int r = 0;
        int l = 0;
        for (auto i : nums) {
            r=max(r,i);
        }
        r=(int)(r+y)/y;
        int m = (r+l)/2;
        int ans=r;
        while (l<=r) {
            m=(r+l)/2;
            int k = m;
            int i = 0;
            //cout<<k<<", "<<l<<", "<<r<<"\n";
            for (i = 0; i < nums.size() && k>=0; i++) {
                if (nums[i]-m*y>0) {
                    int a = x-y;
                    k-=ceil((double)(nums[i]-m*y)/a);
                    if (k<0) {
                        i=0;
                    }
                    //k-=ceil((double)(nums[i]-(k-1)*y)/x);
                }
            }
            if (i==nums.size()) {
                ans=m;
                r=m-1;
            } else {
                l=m+1;
            }
        }
        return ans;
    }
};