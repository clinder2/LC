class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size();
        int m = (l+r)/2;
        while (r-l>1) {
            m=(l+r)/2;
            //cout<<m<<", "<<l<<", "<<r<<"\n";
            int temp = nums[m]-nums[l]-(m-l);
            //cout<<temp<<"\n";
            if (temp>=k) {
                r=m;
            } else {
                k-=temp;
                l=m;
                //cout<<k<<" t\n";
            }
            //cout<<m<<", "<<l<<", "<<r<<" a\n";
        }
        //cout<<k;
        m=(l+r)/2;
        return nums[m]+k;
    }
};