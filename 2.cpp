#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool helper(int index, int n, vector<int> nums, long long target)
    {
        if (index == n - 1)
        {
            if (target == nums[index])
                return true;
            return false;
        }

        long long w1 = helper(index + 1, n, nums, target / nums[index]);
        if (w1)
            return true;
        long long w2 = helper(index + 1, n, nums, target);
        if (w2)
            return true;

        return false;
    };
    bool checkEqualPartitions(vector<int> &nums, long long target)
    {
        int n = nums.size();
        long long P = 1;
        for (int i = 0; i < n; i++)
            P = P * nums[i];
        if (ceil(sqrt(P)) != floor(sqrt(P)))
            return false;
        else if (sqrt(P) != target)
            return false;
    };
};

int main()
{

    return 0;
}