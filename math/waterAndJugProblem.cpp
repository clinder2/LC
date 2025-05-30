class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        int diff = max(x,y)-min(x,y);
        int xd = x-diff;
        int yd = y-diff;
        if (target>x+y) {
            return false;
        }
        if (y-xd==target || x-yd==target) {
            return true;
        }
        if (x+diff==target || y+diff==target) {
            return true;
        }
        if (y-xd+x==target || x-yd+y==target) {
            return true;
        }
        if (x<y) {
            int a = y;
            y=x;
            x=a;
        }
        int temp = x%y;
        int t2 = y-temp;
        if ((target-t2)%y==0) {
            return true;
        }
        if (target%y==0 && target<=x) {
            return true;
        }
        if (diff>0&&(x-target)%diff==0) {
            return true;
        }
        return false;
    }
};