class Solution {
public:
    int lastRemaining(int n) {
        int start = 1;
        int end = n;
        int step = 1;
        int n1 = n;
        for (int i = 1; i <= (int)n1/2 && n>0; i++) {
            int oldstart = start;
            if (n%2==0) {
                start = end;
            } else {
                //cout<<step;
                if (oldstart<end) {
                    start = end-step;
                } else {
                    //cout<<step;
                    start = end+step;
                }
            }
            if (oldstart < end) {
                end = oldstart + step;
            } else if (end<oldstart) {
                end = oldstart - step;
            } else {
                //return start;
            }
            step*=2;
            n/=2;
            //cout<<end<<", "<<start<<", "<<n<<", "<<step<<"\n";
        }
        return end;
    }
};