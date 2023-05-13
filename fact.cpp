#include <iostream>

using namespace std;

// Function to compute the factorial of a number using recursion
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n = 5;
    int result = factorial(n);
    cout << "The factorial of " << n << " is " << result << endl;
    return 0;
}
