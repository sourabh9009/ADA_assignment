#include <iostream>
#include <climits>
#include <vector>

using namespace std;

// Function to compute the minimum number of scalar multiplications needed to multiply a chain of matrices
int matrixChainMultiplication(vector<int>& dimensions) {
    int n = dimensions.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Fill in the diagonal of the DP table with zeros
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    // Fill in the upper triangle of the DP table
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + dimensions[i] * dimensions[k+1] * dimensions[j+1]);
            }
        }
    }

    // Return the minimum number of scalar multiplications needed to multiply the entire chain
    return dp[0][n-1];
}

int main() {
    vector<int> dimensions = {10, 30, 5, 60};
    int result = matrixChainMultiplication(dimensions);
    cout << "The minimum number of scalar multiplications needed to multiply the chain of matrices is: " << result << endl;
    return 0;
}
