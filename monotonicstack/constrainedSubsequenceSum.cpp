class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<pair<int,int>> q;
        //q.push_back(make_pair(nums[0],0));
        int m = 0;
        if (nums[0]>0) {
            q.push_back(make_pair(nums[0],0));
            q.push_back(make_pair(0,0));
        } else {
            q.push_back(make_pair(0,0));
            q.push_back(make_pair(nums[0],0));
        }
        int ans=q[0].first;
        m=nums[0];
        for (int i = 1; i < nums.size(); i++) {
            //cout<<curr<<" c\n";
            m=max(m,nums[i]);
            while (q.size()>0 && q.front().second<i-k) {
                //cout<<q.front().second<<", "<<i<<"\n";
                q.erase(q.begin());
            }
            int curr=max(0,q.front().first)+nums[i];
            ans=max(ans,curr);
            pair<int,int> p=make_pair(curr,i);
            while (q.size()>0 && q.back().first<=curr) {
                q.pop_back();
            }
            q.push_back(p);
            //q.push_back(make_pair(0,i));
        }
        return ans==0 ? m : ans;
    }
};