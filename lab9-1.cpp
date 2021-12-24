class Solution {
public:
    int countArea(vector<vector<int>>& land, int i, int j) {
        if (i < 0 || i >= land.size() || j < 0 || j >= land[0].size()) {
            return 0;
        }
        if (land[i][j] != 0) {
            return 0;
        }
        land[i][j] = -1;
        return 1 + countArea(land, i + 1, j) + countArea(land, i - 1, j) + 
                   countArea(land, i, j + 1) + countArea(land, i, j - 1) + 
                   countArea(land, i + 1, j + 1) + countArea(land, i + 1, j - 1) + 
                   countArea(land, i - 1, j + 1) + countArea(land, i - 1, j - 1);
    }

    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<int> ret;
        for (int i = 0; i < land.size(); i++) {
            for (int j = 0; j < land[0].size(); j++) {
                if (land[i][j] == 0) {
                    ret.push_back(countArea(land, i, j));
                }
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};
