class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        vector<int> seen(values.size());
        long long ans=0;
        int index=0;
        while (true) {
            if (index<0 || index>=values.size() || seen[index]) {
                return ans;
            }
            seen[index]=1;
            //cout<<index<<", ";
            string s = instructions[index];
            if (s=="add") {
                //seen[index]=1;
                ans+=values[index++];
            } else if (s=="jump") {
                index+=values[index];
            }
        }
        return ans;
    }
};