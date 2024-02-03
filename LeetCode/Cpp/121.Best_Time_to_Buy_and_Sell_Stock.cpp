#include "problems.h"
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int min = 0;
        int max = 0;
        int diff = -1;

        if (prices.size() == 1)
        {
            return (0);
        }    
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[min] >= prices[i])
            {
                min = i;
                if (max < min)
                {
                    max = min;
                }
            }
            if (prices[max] <= prices[i] && diff < prices[i] - prices[min])
            {
                max = i;
                diff = prices[max] - prices[min];
            }
        }
        return (diff);
    }
};
