class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if (k>=cardPoints.size()) {
            int a = 0;
            for (auto i : cardPoints) {
                a+=i;
            }
            return a;
        }
        int s=0;
        int r = 0;
        int l=cardPoints.size()-1;
        int k2=k;
        while (k2>0) {
            k2--;
            s+=cardPoints[l--];
        }
        l++;
        int ans = s;
        while (r<k) {
            s-=cardPoints[l++];
            s+=cardPoints[r++];
            ans=max(ans,s);
        }
        return ans;
    }
};