class Solution {
public:
    vector<int> arr;
    int sum;
    Solution(vector<int>& w) {
        arr=vector<int>(w.size());
        int prev = w[0];
        arr[0] = w[0];
        for (int i = 1; i < w.size(); i++) {
            arr[i] = w[i]+prev;
            prev+=w[i];
        }
    }
    
    int pickIndex() {
        float ra = (float)rand()/RAND_MAX;
        ra*=arr.back();
        int l=0;
        int r = arr.size();
        int m = (l+r)/2;
        while (l<=r) {
            m = (l+r)/2;
            if (arr[m]>ra) {
                r=m-1;
            } else {
                l=m+1;
            }
        }
        while (m<arr.size()&&arr[m]<ra) {
            m++;
        }
        while (m>=1&&arr[m-1]>ra) {
            m--;
        }
        cout<<m<<", "<<ra<<"\n";        
        return m;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */