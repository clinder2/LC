class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int index=0;
        int ans=0;
        int m = 1000000007;
        vector<int> d(nums.size());
        d[0]=1;
        for (int i = 1; i < nums.size(); i++) {
            d[i]=(d[i-1]*2)%m;
        }
        while (index<nums.size() && nums[index]*2<=target) {
            long long temp = d[index];
            ans+=temp%m;
            //cout<<(int)pow(2, (int)index)<<" a ";
            ans%=m;
            index++;
        }
        int l = index;
        while (index<nums.size()) {
            while (l>=0 && nums[l]+nums[index]>target) {
                l--;
            }
            if (l>=0) {
                long long rs = (d[index-l-1])%m;
                long long ls = d[l+1]-1;
                ans+=((rs%m)*(ls%m))%m;
                ans%=m;
                //cout<<ans<<"\n";
            }
            index++;
        }
        return ans;
    }
};