class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int longest = 0;

        for (int x : s) {

            // x is the START of a sequence
            if (s.find(x - 1) == s.end()) {

                int length = 1;

                // Keep looking for x+1, x+2, ...
                while (s.find(x + length) != s.end()) {
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};