class Solution {
public:
    int minSteps(int n) {
        if (n<=1) {
            return 0;
        }
        int temp=n/2;
        while (temp>0 && n%temp!=0) {
            temp--;
        }
        if (temp==1) {
            return n;
        }
        return 1+(n/temp-1)+minSteps(temp);
    }
};