#include <iostream>
using namespace std;

// Function to implement Extended Euclidean Algorithm
int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// Function to calculate modular inverse
int modInverse(int a, int m) {
    int x, y;
    int gcd = extendedGCD(a, m, x, y);

    // Check if inverse exists
    if (gcd != 1) {
        cout << "Inverse doesn't exist\n";
        return -1;
    } else {
        // m is added to handle negative x
        return (x % m + m) % m;
    }
}

int main() {
    int a, m;
    cout << "Enter number and modulus: ";
    cin >> a >> m;

    int inverse = modInverse(a, m);
    if (inverse != -1) {
        cout << "The modular inverse of " << a << " modulo " << m << " is: " << inverse << endl;
    }

    return 0;
}
