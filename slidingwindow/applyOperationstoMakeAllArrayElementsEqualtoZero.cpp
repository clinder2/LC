class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int total=nums[0];
        vector<int> a(nums.size());
        a[0]=total;
        for (int i = 1; i <= nums.size()-k; i++) {
            if (i>=k) {
                total-=a[i-k];
            }
            int temp = nums[i]-total;
            a[i]=temp;
            //cout<<temp<<", "<<total<<"\n";
            if (temp<0) {
                return false;
            }
            total+=temp;
        }
        for (int i = nums.size()-k+1; i<nums.size(); i++) {
            //cout<<i<<" "<<total<<"\n";
            if (i>=k) {
                total-=a[i-k];
            }
            if (nums[i] && nums[i]!=total) {
                return false;
            }
            //total-=a[i-k];
        }
        return true;
    }
};