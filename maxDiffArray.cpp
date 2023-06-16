// find the max diff between 2 nums num[i] and num[j] where j>i

int maxProfit(vector<int>& prices) {
        int diff = 0;
        int left = 0;
        int right = 1;
        while(right < prices.size() && left<right)
        {
            if(prices[right] - prices[left] < 0)
            {
                left = right;
                right++;
            }
            else
            {
                if(prices[right] - prices[left] > diff)
                {
                    diff = prices[right]-prices[left];
                    right++;
                }
                else
                {
                    right++;
                }
            }
        } 
        return(diff);
    }
