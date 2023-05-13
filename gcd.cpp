 #include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a = 14;
    int b = 21;
    int result = gcd(a, b);
    cout << "The GCD of " << a << " and " << b << " is " << result << endl;
    return 0;
}
