class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minn= prices[0];
        int profit=0;
        for(int i=0;i<prices.size();i++){
            minn=min(minn,prices[i]);
            profit=max(profit,prices[i]-minn);
            
        }
        return profit;
    }
};