// http://leetcode.com/problems/minimum-total-price-after-applying-discounts/

class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), greater<int>());
        sort(discounts.begin(), discounts.end(), greater<int>());
        double curr = 0.0;
        int n = min(prices.size(), discounts.size());
        for (int i = 0; i < n; i++) {
            curr += prices[i] * (100.0 - discounts[i]) / 100.0;
        }
        for (int i = n; i < prices.size(); i++) {
            curr += prices[i];
        }
        return curr;
    }
};