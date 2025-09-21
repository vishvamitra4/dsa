#include <bits/stdc++.h>
using namespace std;

vector<char>E{'0', '2', '4', '6', '8'};
vector<char>O{'1', '2', '3', '5', '7'};

bool is_prime(int num) {
    
}

void helper_1(int index , int n , string result) {
    // if(result.size() == n) cout << result << endl;
    if(index >= n) {
        cout << result << endl;
        return;
    }
    if(index % 2 == 0) {
        for(int i = 0; i < E.size(); i++) {
           result.push_back(E[i]);
           helper_1(index + 1 , n , result);
           result.pop_back(); 
        }
    }else {

    }
};

void helper() {
    int n;
    cin >> n;
    cout << n << endl;
};

int main() {
    int t = 1;
    while(t--) {
        helper();
    };
    return 0;
}