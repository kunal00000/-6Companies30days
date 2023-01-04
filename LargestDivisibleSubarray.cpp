class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        sort(nums.begin(), nums.end());
        int maxim = INT_MIN, maxim_indx = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j >= 0; j--)
            {
                if (nums[i] % nums[j] == 0)
                {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
                if (maxim < dp[i])
                {
                    maxim = dp[i];
                    maxim_indx = i;
                }
            }
        }
        vector<int> v;
        int div = -1;
        cout << maxim_indx << "--" << maxim;
        for (int i = maxim_indx; i >= 0; i--)
        {
            if ((div == -1 || div % nums[i] == 0) && maxim == dp[i])
            {
                v.push_back(nums[i]);
                maxim--, div = nums[i];
            }
        }
        return v;
    }
};