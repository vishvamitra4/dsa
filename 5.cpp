#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(int index , int n , vector<int>& nums , long long target) { 
        // base condition...
        if (index == n - 1) {
            if(target == nums[index]) return true;
            return false;
        };

        long long w1 = helper(index + 1 , n , nums , target/nums[index]); // taking...
        if (w1) return true;
        long long w2 = helper(index + 1 , n , nums , target); // nmo taking....
        if(w2) return true;

        return false;
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        double P = 1;
        for(int i = 0; i < n; i++) P = P * (double)nums[i];

        if(ceil(sqrt(P)) != floor(sqrt(P))) return false;
        else if((long long)sqrt(P) != target) return false;
        return helper(0 , n , nums , target);
    };
};

int main()
{

    return 0;
}