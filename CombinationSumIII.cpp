class Solution
{
public:
    void solve(int k, int target, int i, vector<int> &temp, vector<vector<int>> &ans)
    {
        if (k == 0 && target == 0)
        {
            temp.erase(temp.begin());
            ans.push_back(temp);
            temp.insert(temp.begin(), 0);
            return;
        }
        if (target < 0)
        {
            return;
        }

        // recursive case
        for (int l = i; l <= 9; l++)
        {
            if (l != temp.back())
            {
                temp.push_back(l);
                solve(k - 1, target - l, l + 1, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> temp;
        temp.push_back(0);
        vector<vector<int>> ans;
        solve(k, n, 1, temp, ans);
        return ans;
    }
};