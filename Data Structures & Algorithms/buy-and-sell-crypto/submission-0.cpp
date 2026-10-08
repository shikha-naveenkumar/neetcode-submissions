class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;       // buy day
        int maxProfit = 0;  // best profit

        for (int right = 1; right < prices.size(); right++) {

            // If today's price is cheaper, buy today
            if (prices[right] < prices[left]) {
                left = right;
            }
            else {
                // Profit if we sell today
                int profit = prices[right] - prices[left];

                maxProfit = max(maxProfit, profit);
            }
        }

        return maxProfit;
    }
};