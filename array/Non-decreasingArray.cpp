class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int used=0;
        if (nums.size()<=2) {
            return true;
        }
        for (int i = 1; i < nums.size(); i++) {
            if (used>1) {return false;}
            if (nums[i]<nums[i-1]) {
                if (i+1<nums.size()) {
                    if (i-2>=0 && nums[i]>=nums[i-2]) {
                        used+=1;
                    } else if (nums[i+1]<nums[i]) {
                        return false;
                    } else if (nums[i+1]<nums[i-1]) {
                        if (i-1>0) {
                            return false;
                        } else {
                            used+=1;
                        }
                    } else {
                        used+=1;
                    }
                } else {
                    used+=1;
                }
            }
        }
        if (used>1) {return false;}
        return true;
    }
};