/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int curr=0;
        for (int i = 0; i < n; i++) {
            if (curr>=n) {
                return -1;
            }
            if (i!=curr&&!knows(i, curr)) {
                curr=i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i!=curr) {
                if (knows(curr, i) || !knows(i, curr)) {
                    return -1;
                }
            }
        }
        return curr;
    }
};