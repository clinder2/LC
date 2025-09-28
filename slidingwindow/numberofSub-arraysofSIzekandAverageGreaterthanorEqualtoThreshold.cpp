class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        double roll=0;
        for (int i = 0; i < k; i++) {
            roll+=arr[i];
        }
        roll/=k;
        int l = 0;
        int r = k-1;
        int ans=roll>=threshold ? 1 : 0;
        while (r<arr.size()-1) {
            roll-=arr[l++]/k;
            roll+=arr[++r]/k;
            if (roll>=threshold) {
                ans++;
            }
        }
        return ans;
    }
};