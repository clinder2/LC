class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = ratings.size();
        int prev = 1;
        int des = 1;
        int i = 0;
        while (i < ratings.size()) {
            int old = i;
            prev=1;
            des=1;
            while (i<ratings.size()-1 && ratings[i+1]>ratings[i]) {
                i++;
                ans+=prev;
                prev++;
            }
            while (i<ratings.size()-1 && ratings[i+1]==ratings[i]) {
                i++;
                prev=0;
            }
            int l = 0;
            while (i<ratings.size()-1 && ratings[i+1]<ratings[i]) {
                i++;
                prev--;
                des++;
                if (prev<=0) {
                    ans+=des-1;
                    l=des-1;
                } else {
                    ans+=prev-1;
                    l=prev-1;
                }
            }
            if (prev>0) {
                ans-=(des-1)*(prev-1);
            }
            if (i==old) {
                i++;
            }
        }
        return ans;
    }
};