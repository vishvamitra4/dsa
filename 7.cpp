#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin() , events.end());

        int count = 0;
        int last_event = 0;

        for(int i = 0; i < n; i++) {
            if(events[i][0] <= last_event + 1 <= events[i][1]) {
                last_event++;
                count++;
            };
        };

        return count;
    }
};

int main() {

    return 0;
}