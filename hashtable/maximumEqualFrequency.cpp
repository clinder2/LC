class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        if (nums.size()==2) {return 2;}
        int levels=0;
        int maxl=0;
        int dist=0;
        map<int,int> count;
        map<int,int> lc;
        int ans=0;
        int n=0;
        for (int i = 0; i < nums.size(); i++) {
            n=nums[i];
            if (!count[n]) {dist++;}
            lc[count[n]]--;
            if (!lc[count[n]]) {levels--;}
            count[n]++;
            maxl=max(maxl,count[n]);
            lc[count[n]]++;
            if (lc[count[n]]==1) {levels++;}
            if (levels==2) {
                if (lc[1]==1) {
                    ans=i+1;
                } else if (lc[maxl]==1 && lc[maxl-1]) {
                    ans=i+1;
                }
            } else if (levels==1 && (maxl==1 || dist==1)) {
                ans=i+1;
            }
        }
        return ans;
    }
};