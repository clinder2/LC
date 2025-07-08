class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> T(nums.size());
        vector<int> T2(nums.size());
        vector<int> ans;
        T[0]=1;
        T2[T2.size()-1]=1;
        int n = nums.size();
        for (int i = 1; i < T.size(); i++) {
            T[i]=nums[i]<=nums[i-1] ? T[i-1]+1 : 1;
            T2[n-i-1]=nums[n-i-1]<=nums[n-i] ? T2[n-i]+1 : 1;
        }
        for (int i = k; i < n-k; i++) {
            //cout<<T[i]<<", "<<T2[i]<<"\n";
            if (T[i-1]>=k && T2[i+1]>=k) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};