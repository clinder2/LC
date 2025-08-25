class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int l = 0;
        int r = plants.size()-1;
        int a=capacityA;
        int b=capacityB;
        int ans=0;
        while (l<=r) {
            if (l==r) {
                if (max(a, b)<plants[l]) {
                    return ans+1;
                } else {
                    return ans;
                }
            } else {
                if (a<plants[l]) {
                    ans++;
                    a=capacityA-plants[l++];
                } else {
                    a-=plants[l++];
                }
                if (b<plants[r]) {
                    ans++;
                    b=capacityB-plants[r--];
                } else {
                    b-=plants[r--];
                }
            }
        }
        return ans;
    }
};