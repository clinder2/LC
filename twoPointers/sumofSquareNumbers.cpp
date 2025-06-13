class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c==1||c==0||c==2) {
            return true;
        }
        long r = 0;
        long l = 0;
        while (r*r<c) {
            r++;
        }
        if (r*r==c) {
            return true;
        }
        while (r>l) {
            r--;
            while (l*l+r*r<c) {
                l++;
                if (l*l+r*r==c) {
                    return true;
                }
            }
        }
        return false;
    }
};