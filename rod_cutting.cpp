#include <iostream>
#include <vector>

using namespace std;

// Function to compute the maximum value that can be obtained by cutting a rod of length n
// given the price of each possible length from 1 to n
int rodCutting(int n, vector<int>& price) {
    vector<int> dp(n+1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], price[j-1] + dp[i-j]);
        }
    }

    return dp[n];
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 4;
    int result = rodCutting(n, price);
    cout << "The maximum value that can be obtained by cutting a rod of length " << n << " is: " << result << endl;
    return 0;
}
