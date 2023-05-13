#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to find the length of the longest common substring between two strings
int longestCommonSubstring(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    int maxLen = 0;

    // Fill in the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                maxLen = max(maxLen, dp[i][j]);
            }
        }
    }

    // Return the length of the longest common substring
    return maxLen;
}

int main() {
    string s1 = "abcdefg";
    string s2 = "xyzabcd";
    int result = longestCommonSubstring(s1, s2);
    cout << "The length of the longest common substring between " << s1 << " and " << s2 << " is: " << result << endl;
    return 0;
}
