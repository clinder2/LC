class Solution {
public:
    double myPow(double x, int n) {
        if (x==1) {
            return 1;
        }
        if (n<0) {
            int temp=0;
            bool first=false;
            if (n==-2147483648) {
                temp=2147483647;
                first=true;
            } else {
                temp = -1*n;
            }
            return (x<0 && first ? -1 : 1) * 1/myPow(x, temp);
        }
        if (n==0) {
            return 1.0;
        } else if (n==1) {
            return x;
        } else {
            if (n%2==0) {
                double a = myPow(x, (int)n/2);
                return a*a;
            } else {
                double a = myPow(x, (int)n/2);
                return x*a*a;
            }
        }
    }
};