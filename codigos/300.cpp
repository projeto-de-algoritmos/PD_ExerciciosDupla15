class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n, 1);
        
        for (int i = n - 1; i >= 0; i--) 
            for (int j = i + 1; j < n; j++) 
                if (nums[i] < nums[j]) 
                    dp[i] = max(dp[i], 1 + dp[j]);
        
        return *max_element(dp.begin(), dp.end());
    }
};
