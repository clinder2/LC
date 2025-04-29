#include <vector>
using namespace std;

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long> t(nums.size());
        t[0]=nums[0];
        long long total;
        for (int i = 1; i < nums.size(); i++) {
            t[i]=(t[i-1]+nums[i]);
        }
        total=t[t.size()-1];
        long long ans=nums.size()+1;
        long long ans2=numeric_limits<int>::max();
        for (int i = 0; i < nums.size(); i++) {
            long long l = t[i];
            long long r= 0;
            if (i<nums.size()-1) {
                r=(total-t[i])/(nums.size()-i-1);
            }
            long long temp = (l/(i+1))-r;
            //cout<<", "<<l<<", "<<(nums.size()-i+1)<<"a \n";
            //cout<<temp<<", "<<(l/(i+1))<<", "<<r/(nums.size()-i+1)<<"a \n";
            if (abs(temp)<ans2) {
                ans=i;
                ans2=abs(temp);
            }
            //ans=min(ans, abs(temp));
        }
        if (nums.size()==1) {
            return 0;
        }
        return ans;
    }
};