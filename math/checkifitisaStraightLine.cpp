class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double x = coordinates[1][0]-coordinates[0][0];
        double y = coordinates[1][1]-coordinates[0][1];
        if (x==0) {
            for (int i = 2; i < coordinates.size(); i++) {
                if (coordinates[i][0]!=coordinates[0][0]) {
                    return false;
                }
            }
            return true;
        }
        double prev = y/x;
        for (int i = 2; i < coordinates.size(); i++) {
            double x = coordinates[i][0]-coordinates[0][0];
            double y = coordinates[i][1]-coordinates[0][1];
            if (y/x != prev) {
                return false;
            }
        }
        return true;
    }
};