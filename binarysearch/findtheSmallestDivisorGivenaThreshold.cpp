class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int m = 0;
        for (auto i : nums) {
            m=max(i,m);
        }
        int r = m;
        int l = 0;
        m=(r+l)/2;
        int ans=1;
        while (r>=l) {
            m=max(1,(r+l)/2);
            int temp=0;
            for (auto i : nums) {
                temp+=ceil((i+m-1)/m);
                //cout<<ceil(i/m)<<"\n";
                if (temp>threshold) {
                    break;
                }
            }
            //cout<<temp<<" "<<m<<", ";
            if (temp>threshold) {
                l=m+1;
            } else {
                ans=m;
                r=m-1;
                if (ans==1) {
                    return ans;
                }
            }
        }
        return ans;
    }
};