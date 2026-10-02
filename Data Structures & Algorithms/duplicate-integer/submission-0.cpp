class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int countt = 0;

        for (int i = 0; i < nums.size(); i++) {
            int c = nums[i];

            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == c) {
                    countt++;
                }
            }

            if (countt > 1) {
                return true;
            }

            countt = 0;
        }

        return false;
    }
};