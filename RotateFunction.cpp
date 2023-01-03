class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int bs = 0, es = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            bs += nums[i];
            es += nums[i] * i;
        }
        int max = es;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            es += bs - (nums[i] * nums.size());
            if (max < es)
            {
                max = es;
            }
        }
        return max;
    }
};