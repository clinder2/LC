class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int k) {
        vector<int> freq;
        int currl=1;
        int curr=nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i]==curr) {
                currl++;
            } else {
                freq.push_back(currl);
                currl=1;
                curr=nums[i];
            }
        }
        freq.push_back(currl);
        sort(freq.begin(), freq.end());
        int r = freq.size()-1;
        while (r>=0 && freq[r]==freq.back()) {
            r--;
        }
        int l = 0;
        if (freq.size()-1-r>=k) {
            return 1;
        }
        k-=freq.size()-1-r;
        int ans=0;
        int prev=0;
        while (l+k-1 <= r) {
            int next = l+k-1;
            while (l<=next) {
                ans+=freq[l]-prev;
                prev=freq[l];
                l++;
            }
            prev=0;
            if (ans>=freq.back()) {
                return 1;
            }
        }
        return 0;
    }
};