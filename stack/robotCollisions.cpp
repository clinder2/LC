class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<vector<int>> temp = *(new vector<vector<int>>);
        if (positions.size()==1) {
            return healths;
        }
        for (int i = 0; i < positions.size(); i++) {
            vector<int> t = {positions[i], healths[i], directions[i]=='L' ? 0 : 1, i};
            temp.push_back(t);
        }
        sort(temp.begin(), temp.end());
        int index=0;
        deque<int> r;
        deque<int> in;
        vector<vector<int>> ans;
        while (index<temp.size()) {
            if (temp[index][2]==0) {
                if (r.size()) {
                    while (r.size()>0 && temp[index][1]) {
                        if (r.back()<temp[index][1]) {
                            r.pop_back();
                            in.pop_back();
                            temp[index][1]--;
                        } else if (r.back()==temp[index][1]) {
                            r.pop_back();
                            in.pop_back();
                            temp[index][1]=0;
                        } else {
                            int temp1=r.back();
                            r.pop_back();
                            r.push_back(temp1-1);
                            temp[index][1]=0;
                        }
                    }
                    if (!r.size()) {
                        ans.push_back({temp[index][3], temp[index][1]});
                    }
                } else {
                    ans.push_back({temp[index][3], temp[index][1]});
                }
            } else {
                r.push_back(temp[index][1]);
                in.push_back(temp[index][3]);
            }
            index++;
        }
        while (r.size()) {
            ans.push_back({in.front(), r.front()});
            r.pop_front();
            in.pop_front();
        }
        sort(ans.begin(), ans.end());
        vector<int> ans2;
        for (auto i : ans) {
            if (i[1]) {
                ans2.push_back(i[1]);
            }
        }
        return ans2;
    }
};