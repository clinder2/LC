class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int> p(nums.size());
        if (nums[0]==0) {
            p[0]=1;
        } else {
            p[0]=0;
        }
        for (int i = 1; i < nums.size();i++) {
            p[i]=p[i-1];
            if (!nums[i]) {
                p[i]++;
            }
            //cout<<p[i]<<"\n";
        }
        int max = 0;
        vector<int> ans;
        int n = nums.size()-1;
        for (int i = 0; i <= n+1; i++) {
            int temp=0;
            if (i==0) {
                temp=n+1-p[n];
                max=temp;
                ans.push_back(i);
            } else if (i==n+1) {
                temp=p[n];
                if (temp==max) {
                    ans.push_back(i);
                } else if (temp>max) {
                    ans=*(new vector<int>());
                    ans.push_back(i);
                }
            } else {
                temp = p[i-1]+n+1-i-(p[n]-p[i-1]);
                if (temp==max) {
                    ans.push_back(i);
                } else if (temp>max) {
                    //cout<<i<<"\n";
                    ans=*(new vector<int>());
                    ans.push_back(i);
                    max=temp;
                }
            }
        }
        return ans;
    }
};