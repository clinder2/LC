class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.size()==1) {
            return nums[0];
        }
        sort(nums.begin(),nums.end());
        vector<int> freq(nums.back()+1);
        for (auto i : nums) {
            freq[i]++;
        }
        vector<int> indicies;
        int prev=nums[0];
        int ind=0;
        for (auto i : nums) {
            if (i!=prev) {
                prev=i;
                indicies.push_back(ind-1);
            }
            ind++;
        }
        indicies.push_back(ind-1);
        if (indicies.size()==1) {
            return freq[nums[0]]*nums[0];
        }
        vector<int> T(indicies.size());
        T[0]=freq[nums[0]]*nums[0];
        if (nums[indicies[1]]-nums[indicies[0]]==1) {
            T[1]=max(T[0], freq[nums[indicies[1]]]*nums[indicies[1]]);
        } else {
            T[1]=T[0]+freq[nums[indicies[1]]]*nums[indicies[1]];
        }
        for (int i = 2; i < T.size(); i++) {
            if (nums[indicies[i]]-nums[indicies[i-1]]==1) {
                //cout<<freq[nums[indicies[i-1]]]<<"\n";
                //cout<<T[i-1]<<"\n";
                T[i]=max(freq[nums[indicies[i]]]*nums[indicies[i]]+T[i-2],T[i-1]);
            } else {
                T[i]=freq[nums[indicies[i]]]*nums[indicies[i]]+T[i-1];
            }
        }
        return T.back();
    }
};