class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Count frequency of each number
        for (int x : nums) {
            freq[x]++;
        }

        // bucket[i] = numbers that appear i times
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto& pair : freq) {
            int number = pair.first;
            int frequency = pair.second;

            bucket[frequency].push_back(number);
        }

        // Start from highest frequency
        vector<int> ans;

        for (int i = nums.size(); i >= 1 && ans.size() < k; i--) {
            for (int x : bucket[i]) {
                ans.push_back(x);

                if (ans.size() == k) {
                    break;
                }
            }
        }

        return ans;
    }
};